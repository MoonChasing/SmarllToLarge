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
#define MAXN 300010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
int a[MAXN];
int b[MAXN];
LL sa[MAXN], sb[MAXN];
LL isa[MAXN], dsa[MAXN], isb[MAXN], dsb[MAXN];

LL qiua(int st, int i)
{
    LL ret = dsa[i] + sa[i] * (st-i);
    ret += isb[i] + sb[i] * (st+n-i);
    return ret;
}

LL qiub(int st, int i)
{
    LL ret = dsb[i] + sb[i] * (st-i);
    ret += isa[i] + sa[i] * (st+n-i);
    return ret;
}
int main()
{
    scanf("%d", &n);
    for(int j=0; j<n; j++)
        scanf("%d", &a[j]);
    for(int j=0; j<n; j++)
        scanf("%d", &b[j]);

    sa[n] = 0, sb[n] = 0;
    isa[n] = 0;
    isb[n] = 0;
    dsa[n] = 0;
    dsb[n] = 0;
    for(int i=n-1; i>=0; i--)
    {
        sa[i] = sa[i+1]+a[i];
        sb[i] = sb[i+1]+b[i];
        isa[i] = isa[i+1] + (LL)a[i]*(n-1-i);
        isb[i] = isb[i+1] + (LL)b[i]*(n-i-1);
        dsa[i] = dsa[i+1] + (LL)a[i]*i;
        dsb[i] = dsb[i+1] + (LL)b[i]*i;
    }

    LL ans = 0;
    LL temp = 0;

    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            ans = max(ans, temp+qiua(2*i, i));
            temp += (LL)2*i*a[i];
            temp += (LL)(2*i+1)*b[i];
        }
        else
        {
            ans = max(ans, temp+qiub(2*i, i));
            temp += (LL)2*i*b[i];
            temp += (LL)(2*i+1)*a[i];
        }

    }
    printf("%lld\n", ans);
    return 0;
}












