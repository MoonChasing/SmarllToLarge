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
typedef long long LL;

using namespace std;

int piaoshu[LONG_MAX];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int maxpiao = 0;
    int ss = m/2;
    int ans = -1;
    for(int i=1; i<=m; i++)
    {
        piaoshu[i]++;
        if( piaoshu[i] > ss)
            ans = i;
    }

        printf("%d\n",ans);
    return 0;
}
