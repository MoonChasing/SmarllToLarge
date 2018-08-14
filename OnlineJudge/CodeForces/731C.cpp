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
#define MAXN 200010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int par[MAXN], urank[MAXN];
int a[MAXN];
vector<int> b[MAXN];
int n, m, k;

void init()
{
    for(int i=1; i<=n; i++)
    {
        par[i] = i;
        urank[i] = 0;
    }
}

int ufind(int x)
{
    if(par[x] == x)
        return x;
    else
        return par[x] = ufind(par[x]);
}

void unite(int x, int y)
{
    x = ufind(x);
    y = ufind(y);
    if(x == y)
        return;
    if(urank[x] < urank[y])
        par[x] = y;
    else
    {
        par[y] = x;
        urank[x]++;
    }
}

bool same(int x, int y)
{
    return ufind(x) == ufind(y);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    init();
    for(int i=1; i<=n; i++)
        scanf("%d", a+i);

    int x, y;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d", &x, &y);
        unite(x, y);
    }

    for(int i=1; i<=n; i++)
        b[ufind(i)].push_back(a[i]);

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(b[i].size() <= 1)
            continue;
        map<int, int> mp;
        int maxx = 0;
        for(int j=0; j<b[i].size(); j++)
        {
            mp[b[i][j]]++;
            maxx = max(maxx, mp[b[i][j]]);
        }
        ans += b[i].size()-maxx;
    }
    printf("%d\n", ans);
    return 0;
}












