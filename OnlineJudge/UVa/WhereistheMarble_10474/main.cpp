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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int main()
{
    int n,q,x,a[MAXN],kiss=0;
    while(scanf("%d%d", &n, &q) == 2 && n)
    {
        printf("CASE# %d:\n",++kiss);
        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        sort(a, a+n);
        while(q--)
        {
            scanf("%d", &x);
            int p = lower_bound(a, a+n, x) - a;
            if(a[p] == x)
                printf("%d found at %d\n", x, p+1);
            else
                printf("%d not found\n", x);
        }
    }
    return 0;
}









