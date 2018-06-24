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
#define MAXN 110
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

struct good
{
    int t,d,p;
}foo[MAXN];

bool cmp(good a, good b)
{
    return a.d < b.d;
}

int cnt = 0;
int n;
int dp[MAXN][2001];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d", &foo[cnt].t, &foo[cnt].d, &foo[cnt].p);
        if(foo[cnt].t >= foo[cnt].d)
            continue;
        else
            cnt++;
    }

    sort(foo, foo+cnt, cmp);

    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<=2000; j++)
        {
            dp[i+1][j] = dp[i][j];
        }
        for(int j=foo[i].t; j<foo[i].d; j++)
            dp[i+1][j] = max(dp[i+1][j], dp[i][j-foo[i].t]+foo[i].p);
    }
    int ans = -1;
    for(int i=0; i<=2000; i++)
        ans = max(ans, dp[cnt][i]);
    printf("%d\n", ans);
    return 0;
}










