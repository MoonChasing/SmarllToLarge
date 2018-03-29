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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
//#define DataIn
typedef long long LL;

using namespace std;

bool vis[MAXN];
int par[MAXN], u_rank[MAXN];
int num;
bool ok;
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        vis[i] = false;
        par[i] = i;
        u_rank[i] = 0;
    }
}

int u_find(int x)
{
    if(par[x] == x)
        return x;
    else
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

int main()
{
    #ifdef DataIn
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    int x, y;
    init(MAXN);
    ok = true;
    while( scanf("%d%d", &x, &y)==2 && ~x & ~y )
    {
        if(x==0 && y==0)
        {
            int sum = 0;
            for(int i=1; i<=MAXN; i++)
            {
                if(vis[i] && par[i] == i)
                    sum++;
            }
            if(sum>1)
                ok = false;
            printf("%s\n", ok ? "Yes" : "No");
            init(MAXN);
            ok = true;
            continue;
        }
        if(ok)
        {
            if(same(x, y))
            {
                ok = false;
            }
            else
            {
                unite(x, y);
                vis[x] = true;
                vis[y] = true;
            }
        }
    }


    return 0;
}












