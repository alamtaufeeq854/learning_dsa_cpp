// Array as Parameters
#include <iostream>
using namespace std;

int fun(int A[], int n) // Array is always pass by address, neither by value nor reference
{
    cout << "Inside Function fun:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    A[3] = 0;
    A[2] = 9;
}

int main()
{
    int A[5] = {8, 6, 3, 2, 7};

    cout << "Inside Main Function:" << endl;

    for (int x : A)
    {
        cout << x << endl;
    }

    fun(A, 5);

    cout << "Inside Main Function After the Function fun:" << endl;

    for (int x : A)
    {
        cout << x << endl;
    }

    return 0;
}