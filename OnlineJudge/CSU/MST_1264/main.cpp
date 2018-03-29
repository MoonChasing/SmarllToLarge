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
#define DataIn
typedef long long LL;

using namespace std;
const int M = 105, N = 10001;

int par[M];
int rak[N];
int m,n;

typedef struct
{
    int u,v,w;
}P;
vector<P> guan;

bool cmp(P a, P b)
{
    return a.w < b.w;
}

void initufs()
{
    for(int i=1; i<=m; i++)
        par[i] = i;
    memset(rak, 0, sizeof(rak));
}

int findpar(int x)
{
    if(par[x] == x)
        return x;
    else
        return par[x] = findpar(par[x]);
}

void uniteufs(int x, int y)
{
    x = findpar(x);
    y = findpar(y);

    if(x == y)
        return;

    if(rak[x] < rak[y])
        par[x] = y;
    else
    {
        par[y] = x;
        if(rak[x] == rak[y])
            rak[x]++;
    }
}

bool same(int x, int y)
{
    return findpar(x) == findpar(y);
}

int main()
{
    while(~scanf("%d%d", &m, &n))
    {
        initufs();
        guan.clear();
        int ans = 0;
        int u,v,w;
        bool flag = true;
        int suiji;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            guan.push_back(P{u,v,w});
        }

        sort(guan.begin(), guan.end(), cmp);

        for(int i=0; i<n; i++)
        {
            if(same(guan[i].u, guan[i].v))
                continue;
            else
            {
                uniteufs(guan[i].u, guan[i].v);
                ans += guan[i].w;
            }
        }
        for(int i=1; i<=m; i++)
        {
            if(i==1)
                suiji = 2;
            else
                suiji = i-1;

            if(par[i] == i && findpar(suiji) != i)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            printf("%d\n",ans);
        else
            puts("?");
    }
    return 0;
}









