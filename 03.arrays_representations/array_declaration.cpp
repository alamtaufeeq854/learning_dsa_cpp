// Array Declaration
#include <iostream>
using namespace std;

int main()
{

    int A[5]; // Garbage Values
    int B[5] = {2, 8, 6, 7, 9};
    int C[5] = {7}; // All Remaining elements becomes '0'
    int D[5] = {0}; // All Remaining elements becomes '0'
    int E[] = {8, 9, 5, 6, 2, 7, 5, 6, 4, 5};
    int F[5] = {}; // All elements becomes '0'

    cout << endl
         << "For Array A: " << endl;
    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
    {
        cout << A[i] << endl;
    }

    cout << endl
         << "For Array B: " << endl;
    for (int i = 0; i < (sizeof(B) / sizeof(B[0])); i++)
    {
        cout << B[i] << endl;
    }

    cout << endl
         << "For Array C: " << endl;
    for (int i = 0; i < (sizeof(C) / sizeof(C[0])); i++)
    {
        cout << C[i] << endl;
    }

    cout << endl
         << "For Array D: " << endl;
    for (int i = 0; i < (sizeof(D) / sizeof(D[0])); i++)
    {
        cout << D[i] << endl;
    }

    cout << endl
         << "For Array E: " << endl;
    for (int i = 0; i < (sizeof(E) / sizeof(E[0])); i++)
    {
        cout << E[i] << endl;
    }

    cout << endl
         << "For Array F: " << endl;
    for (int i = 0; i < (sizeof(F) / sizeof(F[0])); i++)
    {
        cout << F[i] << endl;
    }

    return 0;
}