// Modular Programing
#include <iostream>
#include <stdio.h>
using namespace std;

int area(int length, int breadth)
{
    return length * breadth;
}

int perimeter(int length, int breadth)
{
    return 2 * (length + breadth);
}

int main()
{
    int length = 0, breadth = 0;

    printf("Enter Length here: ");
    cin >> length;

    printf("Enter Breadth here: ");
    cin >> breadth;

    printf("Area is %d\nPerimeter is %d\n", area(length, breadth), perimeter(length, breadth));

    return 0;
}
