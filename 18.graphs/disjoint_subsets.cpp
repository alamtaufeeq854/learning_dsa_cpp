// Disjoint Subsets

#include <stdio.h>

#define N 7

int parent[N];
int rankArr[N];

void makeSet()
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int findSet(int x)
{
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int x, int y)
{
    int px = findSet(x);
    int py = findSet(y);

    if (px == py)
        return;

    if (rankArr[px] < rankArr[py])
        parent[px] = py;
    else if (rankArr[px] > rankArr[py])
        parent[py] = px;
    else
    {
        parent[py] = px;
        rankArr[px]++;
    }
}

int main()
{
    makeSet();

    unionSet(0, 1);
    unionSet(1, 2);
    unionSet(3, 4);
    unionSet(5, 6);
    unionSet(4, 5);

    for (int i = 0; i < N; i++)
        printf("Element %d -> Set %d\n", i, findSet(i));

    return 0;
}
