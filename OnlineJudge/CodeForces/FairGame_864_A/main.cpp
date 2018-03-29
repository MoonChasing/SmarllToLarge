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

int num[200];
int cnt[105];

int main()
{
    int n;
    //memset(num, 0, sizeof(num));
    scanf("%d", &n);
    int m;
    int kiss;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &m);
        num[m]++;
    }

    for(int i=1; i<100; i++)
    {
        if(num[i])
            cnt[num[i]]++;
    }
    for(int i=0; i<100; i++)
    {
        if(cnt[i] >= 2)
        {
            flag = true;
            kiss = i;
            break;
        }
    }

    if(flag)
    {
        puts("YES");
        int cnt = 0;
        for(int i=0; i<105; i++)
        {
            if(num[i] == kiss && cnt == 0)
                {
                    printf("%d ", i);
                    cnt++;
                }
            else if(num[i] == kiss && cnt == 1)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    else
        puts("NO");
    return 0;
}











