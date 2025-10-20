#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int a = 10;
    int *p;

    p = &a;

    printf("%d is accessed by using pointer %p\n", a, p);

    return 0;
}