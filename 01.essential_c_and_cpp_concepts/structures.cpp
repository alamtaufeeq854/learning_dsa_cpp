#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x; //  padding
};

int main()
{
    struct Rectangle r = {10, 5}; // intialisation

    printf("%d\n", sizeof(r));

    cout << r.length << endl;
    cout << r.breadth << endl;

    r.length = 8;
    r.breadth = 4;

    cout << r.length << endl;
    cout << r.breadth << endl;

    return 0;
}