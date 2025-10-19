// Arrays Basics
#include <iostream>
using namespace std;

int main()
{
    int A[5]; // Array Declared
    A[0] = 6;
    A[1] = 8;
    A[2] = 7;

    cout << endl
         << "Array Declaration " << endl;
    cout << sizeof(A) << endl; // Size of Array
    cout << A[1] << endl;
    printf("%d\n", A[2]);

    int B[10] = {8, 6, 7, 4, 9}; // Array Initialised

    cout << endl
         << "Array Initialisation " << endl;
    cout << sizeof(B) << endl; // Size of Array
    cout << B[9] << endl;      // Having some Garbage Value
    printf("%d\n", B[2]);

    cout << endl
         << "Array Declaration Elements Through for loop " << endl;
    for (int i = 0; i < 5; i++) // Use of for loop
    {
        cout << A[i] << endl;
    }

    cout << endl
         << "Array Initialisation Elements Through for each loop " << endl;
    for (int X : B) // use of for each loop
    {
        cout << X << endl;
    }

    return 0;
}
