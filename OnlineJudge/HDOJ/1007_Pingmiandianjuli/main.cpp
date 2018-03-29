#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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

int n;
struct pos
{
    double x, y;
};

pos p[MAXN];
double dis(pos a, pos b)
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return  sqrt(x*x + y*y);
}

bool cmp(pos a, pos b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}


double solve(int l, int r)
{
    if(l>=r)
        return 0;
    if(r == l+1)
        return dis(p[l], p[r]);

    int mid = (l+r)>>1;
    double d = min(solve(l, mid), solve(mid, r));

    for(int i=mid-1; i>=l && p[mid].x - p[i].x < d; i--)
    {
        for(int j = mid+1; j<=r && p[j].x - p[mid].x < d && fabs(p[j].y - p[i].y) < d; j++)
        {
            d = min(d, dis(p[i], p[j]) );
        }
    }
    return d;
}

int main()
{
    while( scanf("%d", &n) && n)
    {

        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        if(n == 1)
        {
            printf("0.00\n");
            continue;
        }
        sort(p, p+n, cmp);
        double d = solve(0, n-1);
        printf("%.2f\n", d/2);
    }

    return 0;
}













