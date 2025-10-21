// Pointer to structure
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r = {10, 5};

    cout << r.length << endl;
    cout << r.breadth << endl;

    struct Rectangle *p = &r;

    cout << p->length << endl;
    cout << p->breadth << endl;

    return 0;
}