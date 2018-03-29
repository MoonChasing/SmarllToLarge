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
#define MAXN  100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
int bit[MAXN];
int n,a,b;
void update(int x, int val)
{
    while(x>0)
    {
        bit[x] += val;
        x -= x&-x;
    }
}

int query(int x)
{
    int sum = 0;
    while(x<=n)
    {
        sum += bit[x];
        x += x&-x;
    }
    return sum;
}


int main()
{
//    while(scanf("%d", &n) && n)
//    {
//        memset(bit, 0, sizeof(bit));
//        for(int i=1; i<=n; i++)
//        {
//            scanf("%d%d",&a, &b);
//            update(b, 1);
//            update(a-1, -1);
//        }
//        for(int i=1; i<n; i++)
//            printf("%d ", query(i));
//        printf("%d\n", query(n));
//    }
    int x=2,y;
    float f = 5.0;
    x>0? y=x:y=-x;
    y = x = f/2;
    return 0;
}


