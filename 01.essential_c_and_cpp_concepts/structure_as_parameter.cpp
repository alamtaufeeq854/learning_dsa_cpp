// structure as parameter
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void fun(struct Rectangle r)
{
    r.length = 8;
    r.breadth = 3;

    cout << "Inside Function fun:" << endl
         << "Length is " << r.length << endl
         << "Breadth is " << r.breadth << endl;
}

void fun2(struct Rectangle *r)
{
    r->length = 78;
    r->breadth = 43;

    cout << "Inside Function fun2:" << endl
         << "Length is " << r->length << endl
         << "Breadth is " << r->breadth << endl;
}

void fun3(struct Rectangle &r)
{
    r.length = 65;
    r.breadth = 94;

    cout << "Inside Function fun3:" << endl
         << "Length is " << r.length << endl
         << "Breadth is " << r.breadth << endl;
}

int main()
{
    struct Rectangle r = {10, 5};

    printf("Length is %d\nBreadth is %d\n", r.length, r.breadth);

    cout << endl
         << "Call by Value: " << endl;
    fun(r);
    cout << "After the function fun: " << endl;
    printf("Length is %d\nBreadth is %d\n", r.length, r.breadth);

    cout << endl
         << "Call by Address: " << endl;
    fun2(&r);
    cout << "After the function fun2: " << endl;
    printf("Length is %d\nBreadth is %d\n", r.length, r.breadth);

    cout << endl
         << "Call by Reference: " << endl;
    fun3(r);
    cout << "After the function fun3: " << endl;
    printf("Length is %d\nBreadth is %d\n", r.length, r.breadth);

    return 0;
}