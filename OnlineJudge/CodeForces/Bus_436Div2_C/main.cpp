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

int main()
{
    int a,b,f,k;
    while(~scanf("%d%d%d%d", &a, &b, &f, &k))
    {
        int fuel = b;
        int ans = 0;
        bool flag = false;

        while(k--)
        {
            fuel -= k;
            if(fuel<0)
            {
                puts("-1");
                flag = true;
            }
            f = a-f;
            if(fuel < 2*f && k)
            {
                fuel = b;
                ans++;
            }
            else if(fuel < f && k == 0)
            {
                fuel = b;
                ans++;
            }
            fuel -= f;
            if(fuel < 0)
            {
                puts("-1");
                flag = true;
            }
            if(flag)
                break;
        }
        if(!flag)
            printf("%d\n", ans);
    }
    return 0;
}












