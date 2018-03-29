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
#define MAXN 150010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int par[MAXN], ufsrank[MAXN];

void init(int num)
{
    for(int i=1; i<=num; i++)
    {
        par[i] = i;
        ufsrank[i] = 0;
    }
}

int ufsfind(int x)
{
    if(x == par[x])
        return x;
    return par[x] = ufsfind(par[x]);
}

void unite(int x, int y)
{
    x = ufsfind(x);
    y = ufsfind(y);
    if(x == y)
        return;
    if(ufsrank[x] < ufsrank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        ufsrank[x]++;
    }
}

bool same(int x, int y)
{
    return ufsfind(x) == ufsfind(y);
}

int main()
{
    int n,k;
    int op, x, y;
    int ans = 0;
    scanf("%d%d", &n, &k);
    init(3*n);

    for(int i=0; i<k; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if(x<=0 || x>n || y<=0 || y>n)
        {
            ans++;
            continue;
        }
        if(1 == op)
        {
            if(same(x, y+n) || same(x, y+2*n))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x, y);
                unite(x+n, y+n);
                unite(x+2*n, y+2*n);
            }
        }
        else
        {
            if(same(x, y) || same(x, y+2*n))
            {
                ans++;
                continue;
            }
            else
            {
                unite(x, y+n);
                unite(x+n, y+2*n);
                unite(x+2*n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}











