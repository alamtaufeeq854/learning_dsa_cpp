// Increasing Array Size
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int *p, *q;

    p = (int *)malloc(5 * sizeof(int));
    p[0] = 3;
    p[1] = 8;
    p[2] = 7;
    p[3] = 1;
    p[4] = 6;

    q = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 5; i++)
        q[i] = p[i];

    free(p);

    p = q;

    q = NULL;

    for (int i = 0; i < 5; i++)
        printf("%d ", p[i]);

    printf("\nSize of Array p becomes 10 from 5");

    return 0;
}
