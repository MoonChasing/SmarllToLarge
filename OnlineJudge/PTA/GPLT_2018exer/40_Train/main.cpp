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
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int dp[MAXN];
int cnt;
int n;

int main()
{
    cnt = 0;
    fill(dp, dp+MAXN, INF);
    scanf("%d", &n);
    int num;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        int ind = upper_bound(dp, dp+MAXN, num) - dp;
        if(ind == cnt)
        {
            dp[cnt] = num;
            cnt++;
        }
        else
        {
            dp[ind]=num;
        }
    }
    printf("%d\n", cnt);
    return 0;
}





