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
#define MAXN 1000005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n, m;
int divnum[MAXN];
int maxx[MAXN<<2];
LL sum[MAXN<<2];
int a[MAXN];

inline int read()   //这题卡常数，用scanf()读入T了，改做输入挂AC
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void init()
{
    for(int i=1; i<MAXN; i++)
        for(int j=i; j<MAXN; j+=i)
            divnum[j]++;
}

void pushup(int root)
{
    sum[root] = sum[root<<1] + sum[root<<1|1];
    maxx[root] = max(maxx[root<<1], maxx[root<<1|1]);
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        sum[root] = a[l];
        maxx[root] = a[l];
        return;
    }

    int mid = l+r>>1;
    build(root<<1, l, mid);
    build(root<<1|1, mid+1, r);
    pushup(root);
}

void update(int root, int l, int r, int a, int b)
{
    if(maxx[root] <= 2)//1的因子只有1， 2的因子有1、2两个，到此个数不再变化
        return;
    if(l == r)
    {
        maxx[root] = sum[root] = divnum[sum[root]];
        return;
    }

    int mid = l+r>>1;
    if(a<=mid)
        update(root<<1, l, mid, a, b);
    if(b>mid)
        update(root<<1|1, mid+1, r, a, b);
    pushup(root);
}

LL query(int root, int l, int r, int a, int b)
{
//    if(l>b || r<a)
//        return 0;
    if(a<=l && b>=r)
        return sum[root];
    int mid = l+r>>1;
    LL ans = 0;
    if(a <= mid)
        ans += query(root<<1, l, mid, a, b);
    if(b > mid)
        ans += query(root<<1|1, mid+1, r, a, b);
    return ans;
}

int main()
{
    init();

    n=read(), m=read();
    for(int i=1; i<=n; i++)
        a[i] = read();
    build(1, 1, n);
    int op, l ,r;
    for(int i=1; i<=m; i++)
    {
        op = read(), l = read(), r = read();
        if(op == 1)
            update(1, 1, n, l, r);
        else
            printf("%I64d\n", query(1, 1, n, l,r));
    }

    return 0;
}











