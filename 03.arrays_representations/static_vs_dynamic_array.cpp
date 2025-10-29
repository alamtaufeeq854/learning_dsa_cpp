// Static VS Dynamic Array
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int A[5] = {8, 5, 6, 9, 4};

    int *p;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 8;
    p[2] = 7;
    p[3] = 1;
    p[4] = 6;

    // Static Array
    cout << "For Array A: ";
    for (int i = 0; i < 5; i++)
        printf("%d ", A[i]);

    cout << endl;

    // Dynamic Array
    cout << "For Array p: ";
    for (int i = 0; i < 5; i++)
        printf("%d ", p[i]);

    return 0;
}
