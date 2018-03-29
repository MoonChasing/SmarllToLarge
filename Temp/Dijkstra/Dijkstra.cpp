#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
#define INF 0x3f3f3f3f
#define MAXV 300
int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
int V;

void addedge(int u, int v, int x)
{
    cost[u][v] = x;
    cost[v][u] = x;
}

void init()
{
    for(int i=0; i<MAXV; i++)
        fill(cost[i], cost[i]+MAXV, INF);
    fill(d, d + V, INF);
    fill(used, used + V, false);
}

void dijkstra(int s)
{
    d[s] = 0;
    while (true)
    {
        int v = -1;

        for (int u = 0; u < V; u++)
            if (!used[u] && (v == -1 || d[u] < d[v]))
                v = u;

        if (v == -1)
            break;

        used[v] = true;

   		for(int u=0; u<V; u++)
   			d[u] = min(d[u], d[v]+cost[v][u]);
    }
}
int main()
{
    init();
    addedge(1, 2, 7);
    addedge(1, 3, 9);
    addedge(1, 6, 14);
    addedge(2, 3, 10);
    addedge(2, 4, 15);
    addedge(3, 6, 2);
    addedge(3, 4, 11);
    addedge(4, 5, 6);
    addedge(5, 6, 9);
    V = 6;
    dijkstra(1);
    for(int i=1; i<=6; i++)
    	printf("%d\n", d[i]);
    return 0;
}
