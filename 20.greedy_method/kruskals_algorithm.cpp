// Kruskal's Algorithm

#include <stdio.h>

#define V 7
#define E 9

struct Edge
{
    int u;
    int v;
    int w;
};

int parent[V];

// Find operation
int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// Union operation
void unionSet(int u, int v)
{
    parent[v] = u;
}

// Sort edges by weight
void sortEdges(struct Edge edges[])
{
    struct Edge temp;
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskal(struct Edge edges[])
{
    int minCost = 0;
    int count = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sortEdges(edges);

    printf("Edges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v)
        {
            printf("%d -- %d (weight = %d)\n",
                   edges[i].u, edges[i].v, edges[i].w);

            minCost += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", minCost);
}

int main()
{
    struct Edge edges[E] = {
        {0, 1, 28},
        {1, 2, 16},
        {2, 3, 12},
        {3, 4, 22},
        {4, 5, 25},
        {5, 6, 24},
        {6, 0, 10},
        {1, 6, 14},
        {2, 4, 18}};

    kruskal(edges);

    return 0;
}
