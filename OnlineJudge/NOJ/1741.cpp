#include<cstdio>
#define MAXN 1005
#define MOD 2011
using namespace std;

int jiecheng[MAXN];
int dp[MAXN][MAXN];
int ans[MAXN];
void init()
{
    jiecheng[0] = 1;
    for(int i=1; i<=MAXN; i++)
        jiecheng[i] = (jiecheng[i-1] * i) % MOD;

    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        for(int j=i; j<MAXN; j++)
        {
            if(i == j)
                dp[i][i] = jiecheng[i];
            if(i == 1)
                dp[1][j] = 1;
            else
                dp[i][j] = (((i*dp[i][j-1])%MOD) + ((i*dp[i-1][j-1])%MOD))%MOD;
        }
    }

    for(int i=1; i<MAXN; i++)
    {
        for(int j=1; j<=i; j++)
            ans[i] = ((ans[i]%MOD) + (dp[j][i]%MOD) )%MOD;
    }

}
int main()
{
    init();
    int m;
    while(~scanf("%d",&m))
        printf("%d\n",ans[m]);
    return 0;
}
