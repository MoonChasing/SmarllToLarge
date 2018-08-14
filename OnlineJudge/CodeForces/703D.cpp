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
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
const int MAXN = 1e6+10;

int n, q;
int a[MAXN], sum[MAXN], tree[MAXN<<2]; //sum为原数组前缀和
map<int, int> mp;   //mp[i]表示上一次i出现的下标

struct node
{
    int l, r;
    int no;
    int ans;
}Query[MAXN];

bool cmp(node a, node b)
{
    return a.r==b.r ? a.l<b.l : a.r<b.r;
}

bool cmp2(node a, node b)
{
    return a.no < b.no;
}

int lowbit(int k)
{
    return k&(-k);
}

void update(int ind, int val)
{
    while(ind <= n)
    {
        tree[ind] ^= val;
        ind += lowbit(ind);
    }
}

int query(int k)
{
    int ans = 0;
    while(k)
    {
        ans ^= tree[k];
        k -= lowbit(k);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);

    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        scanf("%d%d", &Query[i].l, &Query[i].r);
        Query[i].no = i;
    }

    sum[0] = a[0];
    for(int i=1; i<n; i++)
        sum[i] ^= sum[i-1];

    sort(Query, Query+q, cmp);
    int p = 0;
    for(int i=0; i<q; i++)
    {
        int l=Query[i].l, r=Query[i].r;
        while(p<=r)
        {
            if(mp[a[p]] == 0)
            {
                mp[a[p]] = p;
                update(p, a[p]);
            }
            else
            {
                update(mp[a[p]], a[p]);
                update(p, a[p]);
                mp[a[p]] = p;
            }
            p++;
        }
        Query[i].ans = sum[r] ^ sum[l-1] ^ query(r) ^ query(l-1);
    }

    sort(Query, Query+q, cmp2);
    for(int i=0; i<q; i++)
        printf("%d\n", Query[i].ans);
    return 0;
}













