#include<cstdio>
#include<iostream>
#include<cstring>

//#define LOCAL
//#define DEBUG
#define MAXN 50005
using namespace std;

int T, n;
int kiss = 1;
int a[MAXN];
char ope[10];
int op1, op2;
struct Tree
{
    int val;
    int modify;
}SegTree[MAXN<<2];

void init()
{
    memset(a, 0, sizeof a);
    memset(SegTree, 0, sizeof SegTree);
}
void PushUp(int root)
{
    SegTree[root].val = SegTree[root<<1].val + SegTree[root<<1|1].val;
}

void PushDown(int root)
{
    SegTree[root<<1].val += SegTree[root].modify;
    SegTree[root<<1|1].val += SegTree[root].modify;

    SegTree[root<<1].modify += SegTree[root].modify;
    SegTree[root<<1|1].modify += SegTree[root].modify;

    SegTree[root].modify = 0;
}

void build(int root, int l, int r)
{
    SegTree[root].modify = 0;
    if(l==r)
    {
        scanf("%d", &a[l]);
        SegTree[root].val = a[l];
    }
    else
    {
        int mid = l+r>>1;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        PushUp(root);
    }
}

int query(int root, int l, int r, int a, int b)
{
    if(a>r || b<l)
        return 0;
    if(a<=l && b>=r)
        return SegTree[root].val;
    PushDown(root);
    int mid = l+r>>1;
    return query(root<<1, l, mid, a, b)+query(root<<1|1, mid+1, r, a, b);
//    if(b<=mid)
//        return query(root<<1, l, mid, a, b);
//    else if(a>mid)
//        return query(root<<1|1, mid+1, r, a, b);
//    else
//        return query(root>>1, l, mid, a, b)+query(root>>1|1, mid+1, r, a, b);
}

void update(int root, int l, int r, int a, int b, int modifyVal)
{
    if(a>r || b<l)
        return;
    if(a<=l && b>=r)
    {
        SegTree[root].val += modifyVal;
        SegTree[root].modify += modifyVal;
        return;
    }

    PushDown(root);
    int mid = l+r>>1;
    update(root<<1, l, mid, a, b, modifyVal);
    update(root<<1|1, mid+1, r, a, b, modifyVal);
    PushUp(root);
}

int main()
{
    #ifdef LOCAL
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    #endif
    scanf("%d", &T);
    while(T--)
    {
        init();
        scanf("%d", &n);
        build(1, 1, n);
        printf("Case %d:\n", kiss++);
        while(scanf("%s%d%d",ope, &op1, &op2) && ope[0] !='E')
        {
            if(ope[0] == 'Q')
                printf("%d\n", query(1,1,n,op1,op2));
            else if(ope[0] == 'A')
                update(1, 1, n, op1, op1, op2);
            else if(ope[0] == 'S')
                update(1, 1, n, op1, op1, -op2);
        }

        #ifdef DEBUG
        for(int i=1; i<=40; i++)
            printf("%2d:%5d\n", i, SegTree[i].val);
        for(int i=1; i<=n; i++)
            printf("%d: %d\n",i, a[i]);
        int ans = query(1,1,n,1,8);
        printf("%d", ans);
        #endif

    }

    return 0;
}
