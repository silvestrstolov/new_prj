#include "hall.h"


MyArray::MyArray()
{
    for(int i = 0; i < this->array_lenght; i++)
        this->array[i] = 0;
}

int   MyArray::get_lenght()
{
    return this->array_lenght;
}

float MyArray::get_element(int i)
{
    if ( (i < 0 ) || (i >= this->array_lenght))
        return 0;
    else
        return this->array[i];
}

void  MyArray::set_lenght(int arr_lenght)
{
    if (arr_lenght <= 0)
        return;
    else
        this->array_lenght = arr_lenght;
}

void  MyArray::set_element(int i, float v)
{
    if ( (i < 0 ) || (i >= this->array_lenght))
        return;
    else
        this->array[i] = v;
}

void  MyArray::print_element()
{
        cout << "Printing array:" << endl << endl << endl;
        for (int k=0; k <this->array_lenght; k++)
            cout << this->array[k] << " ";
        cout << endl << endl << endl;
}


void  MyArray::fill_rand_array()
{
    srand(time(nullptr));
    if ( this->array == nullptr )
    {
        cout << "ERROR\n"; return;
    }

    for (int k=0; k < this->array_lenght; k++)
    {
        this->array[k]=rand()%1000;
    }
}

void  MyArray::find_min_array ()
{

        int pos=0,buf=0;
        if (this->array == nullptr)
        {
            cout << "\n!!!ERROR!!! MATRIX == NULL!!!\n"; return;
        }
        for(int i = 0; i < this->array_lenght; i++)
        {
            if ((int)this->array[i] % 2 == 0)
            {
                if(this->array[i] > buf)
                {
                    buf = this->array[i];
                    pos = i;
                }
            }
        }
        cout << "element " << (float) buf << endl << endl;
        cout << "position " << (int) pos << endl << endl;

}


float MyArray::find_prodused_arr ()
{
    float buf=0.0f;
    for(int i=0; i < this->array_lenght; i++)
    {
        int k;
        if(i != this->array_lenght) {k = (i + 1);}
        else k = (0);
        buf = (array[i] * array[k]);
        return buf;
        buf = 0.0f;
    }
}
