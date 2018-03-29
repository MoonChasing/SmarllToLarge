#include <iostream>
#include <cstdio>
#define MAXN 200010

using namespace std;

int n, a[MAXN];
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        long long  sum = 0;
        bool flag = false;

        for(int i=0; i<n; i++)
            scanf("%d", a+i);
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            if(a[i] <= 0 && (sum&1))
            {
                break;
            }
        }

        if( (sum&1) == 0)
            flag = true;

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
