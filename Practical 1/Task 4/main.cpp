#include <iostream>
using namespace std;

int countEven(int *array, int num)
{
    int count = 0;

    for (int i = 0; i < num; ++i)
        if (*(array + i) % 2 == 0) 
            count++;

    return count;
}

double* maximum(double *a, int size) {
    if (size == 0) return NULL;

    double *max = new double;
    for (int i = 0; i < size; i++)
        if (*(a + i) > *max)
            max = (a + i);

    return max;
}

int main()
{
    int vals[] = {4, 7, 11, 2, 1, 8, 10};
    int *valptr = vals;

    double vals1[] = {4, 7, 11, 10000, 1, 3, 505};
    double *valptr1 = vals1;

    cout << countEven(valptr, 7) << endl;
    cout << *maximum(valptr1, 7) << endl;
    return 0;
}