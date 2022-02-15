#include "hall.h"

int** create_din_matrix(int lenght, int high)
{
    int** matrix = nullptr;
    matrix = (int**) malloc (sizeof (int*) * lenght);
    for (int i = 0; i < lenght; i++)
    {
        matrix [i] = (int*) malloc (sizeof (int) * high);
    }
    return matrix;
}

void print_matrix(int** matrix, int lenht, int higt)
{
    cout << "Print Matrix: " << endl;
    for (int i = 0; i < lenht; i++)
    {
        cout << endl <<"\t";
        for (int j = 0; j < higt; j++)
        {
            cout << matrix [i][j] << "\t\t";
        }
        cout << endl;
    }
}

void fill_rand_matrix(int** matrix, int lenght, int hight)
{
    srand(time(nullptr));
    if ( matrix == nullptr )
    {
        cout << "ERROR\n"; return;
    }

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            matrix[i][j] = rand()%100;
        }
    }
}

void find_analog_element(int** matrix,  int lenght, int hight, int val)
{
    int** coordinate_matrix;
    int entri_count = 0;
    int k = 0;
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            if (matrix[i][j] == val)
            {
                entri_count = entri_count + 1;
            }
        }
    }
    coordinate_matrix = create_din_matrix(2,entri_count);
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            if (matrix[i][j] == val)
            {
                coordinate_matrix[0][k] = j;
                coordinate_matrix[1][k] = i;
                k++;
            }
        }
    }
    print_matrix(coordinate_matrix, 2, k);
    free_matrix(coordinate_matrix, lenght);
}

int* route_perimeter (int lenght, int hight, int k)
{
    int* a = (int*) malloc (sizeof (int) * 2);
    if ((k >= 0) && (k <= hight - 2))
    {a[0] = 0; a[1] = k;}
    else if ((k >= hight - 1) && (k <= hight + lenght - 3))
    {a[0] = k - hight + 1; a[1] = hight - 1;}
    else if ((k >= lenght + hight - 2) && (k <= 2 * hight + lenght - 4))
    {a[0] = lenght - 1; a[1] = 2 * hight + lenght - 3 - k;}
    else if ((k >= 2 * hight + lenght - 3) && (k <= 2 * lenght + 2 * hight - 5))
    {a[0] = 2 * hight + 2 * lenght - 4 - k; a[1] = 0;}
    return a;
}

void shift_matrix_border (int** matrix, int lenght, int hight, int pos)
{
    cout << "Initial pos\n" << pos;
    int q = 2 * hight + 2 * lenght - 4;
    while (pos > q) pos -= q;
    cout << "Initial Q\n" << q;
    cout << "Result pos amount: \n" << pos;

    for (int p = 0; p < pos; p++)
    {
        int* buff_ind = route_perimeter (lenght, hight, 0);
        float buffer = matrix[buff_ind[0]] [buff_ind[1]];
        for (int k = 1; k <= q - 1; k++)
        {
            int* k_ind = route_perimeter (lenght, hight, k);
            int* km1_ind = route_perimeter (lenght, hight, k - 1);
            matrix[km1_ind[0]] [km1_ind[1]] = matrix[k_ind[0]] [k_ind[1]];
            free (k_ind); free (km1_ind);
        }
        int* q_ind = route_perimeter (lenght, hight, q - 1);
        matrix[q_ind[0]] [q_ind[1]] = buffer;
        free (q_ind);
        free (buff_ind);
    }
}

void find_inverted_matrix (int **matrix, int lenght, int hight)
{
    float determinant = 0;
    float** inverted_matrix = nullptr;
    inverted_matrix = (float**) malloc (sizeof (float*) * lenght);
    for (int i = 0; i < lenght; i++)
    {
        inverted_matrix [i] = (float*) malloc (sizeof (float) * hight);
    }
    determinant = find_det(matrix, lenght);
    for (int i=0; i < lenght; i++)
    {
        for (int j = 0; j < hight; j++)
        {
            inverted_matrix[i][j] = ( (float)matrix[i][j]  / determinant);
        }
    }
    for (int i = 0; i < lenght; i++)
    {
        cout << endl << "\t";
        for (int j = 0; j < hight; j++)
        {
            cout << inverted_matrix [i][j] << "\t\t";
        }
        cout << endl;
    }
    free (*inverted_matrix);
    inverted_matrix = nullptr;
}

float find_det (int **matrix, int lenght_hight)
{
    if ( lenght_hight == 1)
    {
        return matrix[0][0];
    }
    else if ( lenght_hight == 2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    else if ( lenght_hight >= 3)
    {
        float determinant = 0;
        for ( int j = 0; j < lenght_hight; j++ )
        {
            int** minor = nullptr;
            minor = find_minor (matrix, lenght_hight, j, 0);
            determinant += matrix[0][j] * (find_det( minor, lenght_hight - 1) * ( pow ( -1 , j + 0)));
            free_matrix(minor, lenght_hight - 1);
        }
        return determinant;


    }
}

int** find_minor (int **matrix, int lenght_hight, int b, int a)
{
    int m = 0;
    int n = 0;
    int** minor_matrix = nullptr;
    cout << endl << " Minor " << endl;
cout << "a = " << a << " b = " << b << endl << endl << endl;

    minor_matrix = create_din_matrix (lenght_hight - 1, lenght_hight - 1);
    for ( int i = 1; i < lenght_hight; i++)
    {
        if ( i == a) continue;
        for ( int j = 0; j< lenght_hight; j++)
        {
            if ( j == b ) continue;
            minor_matrix[m][n] = 0;
            minor_matrix[m][n] = matrix[i][j];
            n++;
            cout << "i = " << i << " j = " << j << endl << endl;
            cout << "m = " << m << " n = " << n << endl;
        }
        n = 0;
        m++;
    }
print_matrix(minor_matrix, lenght_hight - 1, lenght_hight - 1);
    return minor_matrix;
}

void free_matrix (int **matrix, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        free( matrix[i] );
    }
    free (matrix);
}



