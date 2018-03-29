#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n = 4;
int W = 5;
int w[4] = {2,1,3,2};
int v[4] = {3,2,4,2};
int dp[5][6];

void solve()
{
    for(int i = n-1; i>=0; i--)
    {
        for(int j=0; j<=W; j++)
        {
            if(j < w[i])
                dp[i][j] = dp[i+1][j];
            else
            {
                dp[i][j] = max( dp[i+1][j], dp[i+1][j-w[i]]+v[i] );
            }
        }
    }

    printf("%d\n",dp[0][W]);
}
int main(void)
{
    int a=3;
    printf("%d",a);
    solve();
    getchar();
    return 0;
}

