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

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int a[MAXN], b[MAXN];
    int ans[MAXN][MAXN];

    int sum = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", a+i);
        sum ^= a[i];
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", b+i);
        sum ^= b[i];
    }
    if(sum)
    {
        puts("NO");
        return 0;
    }

    memset(ans, 0, sizeof(ans));
    ans[0][0] = b[0];
    for(int i=1; i<n; i++)
        ans[0][0] ^= a[i];
    for(int i=1; i<=m; i++)
        ans[0][i] = b[i];
    for(int i=1; i<=n; i++)
        ans[i][0] = a[i];

    int temp = 0;
    for(int i=0; i<=m; i++)
        temp ^= ans[0][i];
    if(temp!=a[0])
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        printf("%d%c", ans[i][j], " \n"[j==m-1]);
    return 0;
}











