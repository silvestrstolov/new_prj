#ifndef HALLS_H
#define HALLS_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <stdio.h>

class MyArray {

private:
    int    array_lenght;
    float  array [];
public:
    MyArray ();
    int   get_lenght       ();
    float get_element      (int i);
    void  set_lenght       (int arr_lenght);
    void  set_element      (int i, float v);
    void  print_element    ();
    void  fill_rand_array  ();
    void  find_min_array   ();
    float find_prodused_arr();
};

#define EPSILON 0.005
using namespace std;
typedef bool (*cmp_func) (float, float);

int menu(void);

//void fill_rand_array (float* arr, int length);
//float* Create_din_arr ( int lenght);
//void print_array (float* arr, int length);
//int find_min_array (float* array, int lenght);
//void find_prodused_arr (float* array, float* prod_arr, int lenght);
int** create_din_matrix (int lenght, int high);
void print_matrix (int** matrix, int lenht, int higt);
void fill_rand_matrix (int** matrix, int lenght, int hight);
void find_analog_element (int** matrix, int lenght, int hight, int val);
void shift_matrix_border (int** matrix, int lenght, int hight, int pos);
int find_determinant (int** matrix, int lenght_hight);
void find_inverted_matrix (int **matrix, int lenght, int hight);
int** find_minor (int **matrix, int lenght_hight, int a, int b);
float find_det (int **matrix, int lenght_hight);
void free_matrix (int **matrix, int rows);

//________________________________________________________________________





float* simple_insertion_sort(MyArray array, MyArray array_lenth,cmp_func f);
float* simple_bubble_sort( float* array, int length, cmp_func f);
float* simple_choice_sort(float* array, int length, cmp_func f);
float* sort_quickly(float* array,int left, int right,cmp_func f);
float* ShellSort(float* array, int length,cmp_func f);
void transposition (float *a, float *b);
void siftDown(float *array, int left, int right,cmp_func f);
float* piramid_sort(float* array, int length, cmp_func f);
bool compare_asc (float a, float b);
bool compare_des (float a, float b);
float* matrix_sort (int** matrix, float *array, int lenght, int hight);
void BinSearch(float *array, int n, int k);


#endif // HALLS_H


