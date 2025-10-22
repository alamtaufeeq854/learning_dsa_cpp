// Monolithic Programing
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int length = 0, breadth = 0;

    printf("Enter Length here: ");
    cin >> length;

    printf("Enter Breadth here: ");
    cin >> breadth;

    int area = length * breadth;
    int peri = 2 * (length + breadth);

    printf("Area is %d\nPerimeter is %d\n", area, peri);

    return 0;
}
