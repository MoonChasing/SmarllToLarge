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
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int card[MAXN];

int main()
{
    int n, num;
    while(~scanf("%d", &n))
    {
        memset(card, 0, sizeof(card));
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &num);
            card[num]++;
        }
        int ans = 0;
        ans += card[1]/2;
        card[1] %= 2;
        ans += card[2]/2;
        card[2] %= 2;
        for(int i=3; i<=n; i++)
        {
            if(card[i] && card[i-1] && card[i-2])
            {
                ans++;
                card[i]--;
                card[i-1]--;
                card[i-2]--;
            }

            ans += card[i]/2;
            card[i] %= 2;


        }
        printf("%d\n", ans);
    }
    return 0;
}








