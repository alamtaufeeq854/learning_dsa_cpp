// Structure and functions
#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialise(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}
int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

int perimeter(struct Rectangle r)
{
    return 2 * (r.length + r.breadth);
}

int main()
{
    struct Rectangle r = {1, 1};

    int length;
    int breadth;

    printf("Enter length here: ");
    cin >> length;

    printf("Enter breadth here: ");
    cin >> breadth;

    initialise(&r, length, breadth);

    printf("Area is %d\nPerimeter is %d\n", area(r), perimeter(r));

    return 0;
}
