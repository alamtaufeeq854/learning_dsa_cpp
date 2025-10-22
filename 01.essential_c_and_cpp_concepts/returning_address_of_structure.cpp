// Returning address of structure
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

struct Rectangle *fun()
{
    struct Rectangle *p;
    p = new Rectangle();

    // or
    //  p = (Rectangle*)malloc(sizeof(struct Rectangle ))

    p->length = 5;
    p->breadth = 10;

    return p;
}

int main()
{
    Rectangle *ptr;
    ptr = fun();

    cout << "Length is " << ptr->length << endl
         << "Breadth is " << ptr->breadth << endl;

    return 0;
}