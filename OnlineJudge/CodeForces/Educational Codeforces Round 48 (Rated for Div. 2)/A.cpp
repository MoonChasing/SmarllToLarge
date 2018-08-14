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
#define MAXN 200005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int main()
{
    int n, m;
    int t[MAXN];
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", t+i);
    }
    int ans = 0, pre = 0;
    for(int i=0; i<n; i++)
    {
        ans = (pre+t[i])/m;
        pre = (pre+t[i])%m;
        printf("%d%c", ans, " \n"[i==n-1]);
    }
    return 0;
}











