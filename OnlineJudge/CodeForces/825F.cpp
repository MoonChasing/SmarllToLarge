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
#define MAXN 8005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;
int next[MAXN];
char s[MAXN];
int len;
int dp[MAXN];
int a[MAXN][MAXN];

void prekmp(char x[])
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < len)
    {
        while(j!=-1 && x[i]!=x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int digitcnt(int k)
{
    int cnt = 0;
    while(k)
    {
        k /= 10;
        cnt++;
    }
    return cnt;
}

void init()
{
    for(int i = 0; i < len; i++)
    {
        prekmp(s + i);
        for(int j = i; j < len; j++)
        {
            if(j == i)
            {
                a[i][j] = 2;
                continue;
            }

            int t1 = j - i + 1, t2 = t1 - next[t1];
            a[i][j] = t1 % t2 == 0 ? t2 + digitcnt(t1/t2) : t1 + 1;
        }
    }
}

int main()
{
    scanf("%s", s);
    len = strlen(s);
    fill(dp, dp+len, INF);
    init();
    dp[0] = 2;
    for(int i = 1; i < len;i ++)
    {
        dp[i] = a[0][i];
        for(int j = 0; j < i; j ++)
            dp[i] = min(dp[i],dp[j] + a[j + 1][i]);
    }
    printf("%d\n",dp[len-1]);

    return 0;
}











