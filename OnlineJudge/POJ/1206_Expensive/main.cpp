#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
int rak[MAXN];
int E[MAXN][MAXN], d[MAXN];
bool vis[MAXN];
int n,m;

void init()
{
    memset(rak, 0, sizeof(rak));
    memset(vis, false , sizeof(vis));
    fill(d, d+MAXN, INF);
    for(int i=0; i<=n+2; i++)
        for(int j=0; j<=n+2; j++)
            E[i][j] = INF;
}

bool rakok(int i)
{
    if(rak[i] >= rak[0] && rak[i]-rak[0] <= m)
        return true;
    return false;
}

int dijkstra()
{
    memset(vis, false, sizeof(vis));
    fill(d, d+MAXN, INF);

    d[0] = 0;
    for(int i=1; i<=n; i++)
    {
        d[i] = E[0][i];
    }

    while(true)
    {
        int v = -1;
        for(int u = 1; u<=n; u++)
            if(!vis[u] && (d[u] < d[v] || v == -1))
                v = u;

        if(v == -1)
            break;
        vis[v] = true;
        if(!rakok(v))
            continue;
        for(int u=1; u<=n; u++)
        {
            if(rakok(u) && d[u] > d[v] + E[v][u])
                d[u] = d[v] + E[v][u];
        }

    }
    return d[1];
}
int main()
{
    scanf("%d%d", &m, &n);
    init();
    for(int i=0; i<=n; i++)
        E[i][i] = 0;
    int k, v, val;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d", &E[0][i], &rak[i], &k);
        while(k--)
        {
            scanf("%d%d", &v, &val);
            E[v][i] = val;
        }
    }

    int ans = INF;
    for(int i=1; i<=n; i++)
    {
        rak[0] = rak[i];
        ans = min(ans, dijkstra());
    }
    printf("%d\n",ans);
    return 0;
}






