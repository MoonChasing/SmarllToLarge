#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 50010
#define MAXK 100010
using namespace std;

int n, k;
int T[MAXK], X[MAXK], Y[MAXK];
int par[MAXN*3];
int u_rank[MAXN];

void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        par[i] = i;
        u_rank[i] = 0;
    }
}

int u_find(int x)
{
    if(x == par[x])
        return x;
    return par[x] = u_find(par[x]);
}

void unite(int x, int y)
{
    x = u_find(x);
    y = u_find(y);

    if(x == y)
        return;
    if(u_rank[x] < u_rank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        u_rank[x]++;
    }
}

bool same(int x, int y)
{
    return u_find(x) == u_find(y);
}

int solve()
{
    init(n*3);
    for(int i=1; i<=k; i++)
    {
        int
    }
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {

        for(int i=1; i<=k; i++)
        {
            scanf("%d%d%d", &T[i], &X[i], &X[i]);
        }
    }
    return 0;
}
