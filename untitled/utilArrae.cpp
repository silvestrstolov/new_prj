#include "hall.h"

float* Create_din_arr( int lenght)
{
    float*temp=nullptr;
    temp=(float*)malloc(lenght*sizeof(float));
    return temp;
}

void fill_rand_array(float* arr, int length)
{
    srand(time(nullptr));
    if ( arr == nullptr )
    {
        cout << "ERROR\n"; return;
    }

    for (int k=0; k < length; k++)
    {
        arr[k]=rand()%1000;
    }
}

void print_array(float* arr, int length)
{
    cout << "Printing array:" << endl << endl << endl;
    for (int k=0; k <length; k++)
        cout << (float)arr[k]<< " ";
    cout << endl << endl << endl;
}

int find_min_array(float* array, int lenght)
{
    int pos=0,buf=0;
    if (array == nullptr)
    {
        cout << "\n!!!ERROR!!! MATRIX == NULL!!!\n"; return 0;
    }
    for(int i = 0; i < lenght; i++)
    {
        if ((int)array[i] % 2 == 0)
        {
            if(array[i] > buf)
            {
                buf = array[i];
                pos = i;
            }
        }
    }
    cout << "element " << (float) buf << endl << endl;
    cout << "position " << (int) pos << endl << endl;
}

void find_prodused_arr(float* array, float* prod_arr, int lenght)
{
    float buf=0.0f;
    for(int i=0; i < lenght; i++)
    {
        int k;
        if(i != lenght) {k = (i + 1);}
        else k = (0);
        buf = (array[i] * array[k]);
        prod_arr[i] = buf;
        buf = 0.0f;
    }
}
