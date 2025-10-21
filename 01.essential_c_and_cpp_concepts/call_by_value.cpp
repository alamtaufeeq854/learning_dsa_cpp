// Call By Value
#include <iostream>
#include <stdio.h>
using namespace std;

void show(int x, int y)
{
    x += 2;
    y += 5;

    printf("Inside function show: %d %d", x, y);
}

int main()
{
    int num1 = 8, num2 = 9;

    show(num1, num2);

    cout << endl
         << "In main function: " << num1 << " " << num2 << endl;

    return 0;
}