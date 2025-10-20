// Pointer to an array in heap
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int *p;
    p = (int *)malloc(5 * sizeof(int)); // In C

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", i + 10);
    }
    free(p); // In C

    cout << endl;

    int *q;
    q = new int[5]; // In C++

    for (int i = 0; i < 5; i++)
    {
        cout << i + 16 << endl;
    }
    delete[] q; // In C++

    return 0;
}