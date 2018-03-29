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
#define MAXN 10005
#define MAXM 20005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

typedef pair<int, int> P;
bool flag;
int n,m,l;
int s,t;
vector<int> E[MAXN];
bool vis[MAXN];
int d[MAXN];
const int len = 1;

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+MAXN, INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty())
    {
        P p = que.top();
        que.pop();

        int v = p.second;
        if(p.first > d[v] )
            continue;
        for(int i=0; i<E[v].size(); i++)
        {
            int to = E[v][i];
            if(d[to] > d[v] + 1)
            {
                d[to] = d[v]+1;
                que.push( P(d[to], to) );
            }
        }
    }
}

void dfs(int u, int dep)
{
    if(flag)
        return;

    if(dep + d[u] > l)
        return;

    if(dep == l && u == t)
    {
        flag = true;
        return;
    }
    if(dep > l || (dep == l && u != t ))
    {
        return;
    }
    vis[u] = true;
    for(int i=0; i<E[u].size(); i++)
    {
        if( !vis[ E[u][i] ] )
            dfs(E[u][i], dep + 1);
        if(flag)
            break;
    }
    vis[u] = false;
}

int main()
{
    scanf("%d%d%d", &n, &m, &l);
    int u,v;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    scanf("%d%d", &s, &t);
    flag = false;
    memset(vis, false, sizeof(vis));
    dijkstra(t);

    dfs(s,0);
    if(flag)
        puts("YES");
    else
        puts("NO");
    return 0;
}





