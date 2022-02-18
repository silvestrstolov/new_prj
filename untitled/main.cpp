#include <QtCore/QCoreApplication>
#include "hall.h"

int main()
{
    int key=0;
    MyArray Prod_array;
    MyArray array;
    float *array2 = nullptr;
    int **matrix = nullptr;
    int find_number;
    int pos;
    int LENGHT = 0;
    int HIGHT = 0;
    int chois = 0;

    cmp_func f=compare_asc;
    cmp_func g=compare_des;

    do
    {
        key=menu();

        switch (key)
        {
        case 1:
            cout << "enter lenght array" << endl;
            cin >> LENGHT;
            array.set_lenght(LENGHT);
            array.fill_rand_array(); break;

        case 2:
            array.find_min_array(); break;
        case 3:
            Prod_array.set_lenght(LENGHT);
            for (int i = 0; i < LENGHT; i++)
            {
                Prod_array.set_element(i,( array.find_prodused_arr()));
            }
            Prod_array.print_element(); break;
        case 4:
            LENGHT = 0;
            HIGHT = 0;
            cout << "enter rang matrix" << endl;
            cin >> LENGHT;
            cin >> HIGHT;
            matrix = create_din_matrix(LENGHT, HIGHT);
            fill_rand_matrix(matrix, LENGHT, HIGHT); break;

        case 5:
            cout << "Enter the required number" << endl;
            cin >> find_number;
            find_analog_element(matrix, LENGHT, HIGHT, find_number); break;
        case 6:
            cout << "Enter posipion" << endl;
            cin >> pos;
            shift_matrix_border(matrix, LENGHT, HIGHT, pos);
            print_matrix(matrix, LENGHT, HIGHT); break;
        case 7:
        {
            if (LENGHT == HIGHT) find_inverted_matrix(matrix, LENGHT, HIGHT);
            else cout << " ERROR, matrix is ​​not square" << endl; break;
        }
        case 8:
            array.print_element(); break;
        case 9:
            print_matrix(matrix, LENGHT, HIGHT); break;
        case 10:
            for (int i = 0; i < LENGHT; i++)
            {
                Prod_array.set_element(i,0);
            }
            Prod_array.print_element(); break;
            LENGHT = 0;
            cout << " enter new lenght" << endl;
            cin >> LENGHT;
            array.set_lenght(LENGHT);
            array.fill_rand_array(); break;
        case 11:
            free_matrix(matrix, LENGHT);
            matrix = nullptr;
            LENGHT = 0;
            HIGHT = 0;
            cout << "enter new rang" << endl;
            cin >> LENGHT;
            cin >> HIGHT;
            matrix = create_din_matrix(LENGHT, HIGHT);
            fill_rand_matrix(matrix, LENGHT, HIGHT); break;
        case 12:

            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;

            if ( chois == 1 )
                array = simple_insertion_sort (array, LENGHT, f);
            else if ( chois == 2 )
                array = simple_insertion_sort (array, LENGHT, g);
            array.print_element(); break;
        case 13:

            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;

            if ( chois == 1 )
                array = simple_bubble_sort (array, LENGHT, f);
            else if ( chois == 2 )
                array = simple_bubble_sort (array, LENGHT, g);
            array.print_element(); break;
        case 14:
            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;

            if ( chois == 1 )
                array = simple_choice_sort (array, LENGHT, f);
            else if ( chois == 2 )
                array = simple_choice_sort (array, LENGHT, g);
            array.print_element(); break;
        case 15:
            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;
             if ( chois == 1 )
            array = sort_quickly (array, 0, LENGHT,f);
             else if ( chois == 2 )
            array = sort_quickly (array, 0, LENGHT,g);
            array.print_element(); break;
        case 16:
            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;
            if ( chois == 1 )
                array = ShellSort (array, LENGHT,f);
            else if ( chois == 2 )
                array = ShellSort (array, LENGHT,g);
            array.print_element(); break;
        case 17:
            cout << "1: sorting from smaller to larger" << endl;
            cout << "2: sotring from larger to smaller" << endl;
            cin >> chois;
            cout << endl;

            if ( chois == 1 )
                array = piramid_sort (array, LENGHT, f);
            else if ( chois == 2 )
                array = piramid_sort (array, LENGHT, g);
            array.print_element(); break;
        case 18:
            array2 = Create_din_arr(LENGHT * HIGHT);
            array2 = matrix_sort(matrix, array2, LENGHT, HIGHT);
            free (array2); break;
        case 19:
            int k = 0;
            cout << "enter element" << endl;
            cin >> k;

            BinSearch(array,LENGHT,k);
            break;
        }
    }
    while (key != 0);
    return 0;

}




