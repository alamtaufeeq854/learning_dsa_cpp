// Object Oriented Program
#include <iostream>
#include <stdio.h>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l = 1, int b = 1)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }
};

int main()
{

    int length;
    int breadth;

    printf("Enter length here: ");
    cin >> length;

    printf("Enter breadth here: ");
    cin >> breadth;

    Rectangle r(length, breadth);

    printf("Area is %d\nPerimeter is %d\n", r.area(), r.perimeter());

    return 0;
}
