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
#define MAXN 1005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

typedef pair<int, int> P;
int E[MAXN][MAXN], hu[MAXN][MAXN];
int d[MAXN];
int cost[MAXN];
int n,m;

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d+1, d+n+1, INF);
    fill(cost+1, cost+n+1, INF);

    d[s] = 0;
    cost[s] = 0;
    que.push(P(0, s));
    while(!que.empty())
    {
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;

        for(int i=1; i<=n; i++)
        {
            if(d[i] > d[v] + E[v][i])
            {
                d[i] = d[v] + E[v][i];
                cost[i] = cost[v] + hu[v][i];
                que.push(P(d[i], i));
            }
            else if(d[i] == d[v] + E[v][i] && cost[i] > cost[v] + hu[v][i])
            {
                cost[i] = cost[v] + hu[v][i];
                //que.push(P(d[e.v], e.v));
            }
        }
    }
}

int main()
{
    int u,v,d,p;
    int s, t;
    while(scanf("%d%d", &n, &m) && n && m)
    {
        for(int i=0; i<n+5; i++)
            for(int j=0; j<n+5; j++)
                hu[i][j] = E[i][j] = INF;

        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d", &u, &v, &d, &p);
            if(E[u][v] > d)
            {
                E[u][v] = E[v][u] = d;
                hu[u][v] = hu[v][u] = p;
            }
            if(E[u][v] == d && hu[u][v] > p)
                hu[u][v] = p;
        }
        scanf("%d%d", &s, &t);

        dijkstra(s);
        printf("%d %d\n", ::d[t], cost[t]);
    }
    return 0;
}










