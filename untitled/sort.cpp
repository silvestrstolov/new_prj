#include "hall.h"


float* simple_insertion_sort(float* array, int length,cmp_func f)
{
    float  x;
    int j=0;
    for ( int i = 1; i < length; i++)
    {
        x = array[i];
        j = i - 1;
        while  (f(x ,array [j]) && (j >= 0))
        {
            array [j + 1] = array [j];

            j--;
        }
        array [j + 1] = x;
    }

    return array;
}

float* simple_bubble_sort( float* array, int length, cmp_func f)
{
    float x;
    for ( int i = 0; i < length - 1; i++)
    {
        for ( int j = length - 1; j > i; j--)
        {
            if (f ( array[j - 1] , array[j]) )
            {
                x = array[j - 1];
                array[j - 1] = array[j];
                array[j] = x;
            }
        }
    }
    return array;
}

float* simple_choice_sort(float* array, int length, cmp_func f)
{
    float x;
    for ( int i = 0; i < length-1; i++)
    {
        x = array[i];
        int index = i;
        for (int j = i + 1; j < length; j++)
        {
            if(f (array[j], x))
            {
                x = array[j];
                index = j;
            }
        }
        array[index] = array[i];
        array[i] = x;
    }
    return array;
}

float* sort_quickly(float* array,int left, int right,cmp_func f)
{
    int i = left;
    int j = right;
    int middle = (left + right) / 2;
    float buff = array[middle];
    while ( i <= j)
    {
        while(f(array[i],buff)) i++;
        while(f(buff,array[j])) j--;
        if(i <= j)
        {
            float t = array[i];
            array[i] = array[j];
            array[j] = t;
            i++;
            j--;
        }
    }
    if(left < j) sort_quickly(array, left, j,f);
    if(i < right) sort_quickly(array, i, right,f);
    return array;
}

float* ShellSort(float* array, int length,cmp_func f)
{
    int i = 0;
    int j = 0;
    int step = 0;
    float tmp;
    for (step = length / 2; step > 0; step /= 2)
        for (i = step; i < length; i++)
        {
            tmp = array[i];
            for (j = i; j >= step; j -= step)
            {
                if (f(tmp,array[j - step]))
                    array[j] = array[j - step];
                else
                    break;
            }
            array[j] = tmp;
        }
    return array;
}

void transposition (float *a, float *b)
{
    float buf = *a;
    *a = *b;
    *b = buf;
}

void siftDown(float *array, int left, int right,cmp_func f)
{
  int maxChild;
  int done = 0;
  while ((left * 2 <= right) && (!done))
  {
    if (left * 2 == right)
      maxChild = left * 2;

    else if (f(array[left * 2],array[left * 2 + 1]))
      maxChild =left * 2;
    else
      maxChild = left * 2 + 1;

    if (f(array[maxChild],array[left]))
    {
      int temp =array[left];
      array[left] = array[maxChild];
      array[maxChild] = temp;
      left = maxChild;
    }
    else
      done = 1;
  }
}

float* piramid_sort(float* array, int lenght, cmp_func f)
{

  for (int i = (lenght / 2) - 1; i >= 0; i--)
    siftDown(array, i, lenght - 1,f);
    for (int i = lenght - 1; i >= 1; i--)
  {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    siftDown(array, 0, i - 1,f);
  }
  return array;
}

bool compare_asc (float a, float b)
{
    if(a < b)
        return true;
    else
        return false;
}

bool compare_des (float a, float b)
{
    if(a > b)
        return true;
    else
        return false;
}

float* matrix_sort (int** matrix, float* array, int lenght, int hight)
{
    int i;
    int q = 0;
    int j = 0;
    int chois = 0;

    cmp_func f=compare_asc;
    cmp_func g=compare_des;
    cout << "1: sorting from smaller to larger" << endl;
    cout << "2: sotring from larger to smaller" << endl;
    cin >> chois;
    cout << endl;

    do
    {
        for( i = 0; i < lenght; i++)
        {
            array[q] = (float)matrix[i][j];
            q++;
        }
        j++;
        for(i = lenght - 1; i >= 0; i--)
        {
            array[q] = (float)matrix[i][j];
            q++;
        }
        j++;
    }

    while(i <= lenght - 1 && j <= hight - 1);
    if ( chois == 1 )
        array = simple_bubble_sort (array, lenght * hight, f);
    else if ( chois == 2 )
        array = simple_bubble_sort (array, lenght * hight, g);

    for (i = 0; i < lenght * hight; i++)
    {
        int c = i / lenght;
        if( c %2 == 0)
        {
            int r = i %lenght;
            matrix[r][c] = (int)array[i];
        }
        else
            if(c %2 == 1)
            {
                int r = i %lenght;
                matrix[lenght - 1 - r][c] = (int)array[i];
            }
    }
    print_matrix(matrix, lenght, hight);
    return array;
}

void BinSearch(float *array, int n, int k)
{
    int L = 0;
    int R = n;
    int m;
    if (array[0] <= array[n])
       {
        while (L<R)
    {
        m = (L+R)/2;
        if (k > array[m]) L = m;
       else if (k < array[m]) R = m;
       else if ((k - array[m]) < EPSILON )
        {
            cout<< endl << "positio = " << m << endl << endl;
            break;
        }
    }
}
    else
    {
        while (L<R)
    {
        m = (L+R)/2;
        if (k > array[m]) R = m;
       else if (k < array[m]) L = m;
       else if ((k - array[m]) < EPSILON )
        {
            cout<< endl << "positio = " << m << endl << endl;
            break;
        }
    }
    }
}
