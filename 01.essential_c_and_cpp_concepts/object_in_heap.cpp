// Object In Heap
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{

    struct Rectangle *p;

    p = new Rectangle(); // In C++

    p->length = 3;
    p->breadth = 4;

    cout << p->length << endl;
    cout << p->breadth << endl;

    struct Rectangle *q;

    q = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // In C

    q->length = 8;
    q->breadth = 7;

    cout << q->length << endl;
    cout << q->breadth << endl;

    return 0;
}