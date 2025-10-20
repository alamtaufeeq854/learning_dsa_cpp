// Pointer to an array
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int A[5] = {2, 9, 8, 3, 7};

    int *p;

    p = A; // Valid
           //   p= &A[0];   // valid
           //   p= &A;       // Invalid

    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }

    return 0;
}