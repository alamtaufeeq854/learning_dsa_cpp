// Call By Address
#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int num1 = 2, num2 = 5;

    cout << "Before swap function: " << num1 << " " << num2 << endl;

    swap(&num1, &num2);

    cout << "After swap function: " << num1 << " " << num2 << endl;

    return 0;
}