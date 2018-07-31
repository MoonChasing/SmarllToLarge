#include <bits/stdc++.h>

using namespace std;

const int MAXN=55;
int p[MAXN], a[MAXN], b[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0, sum2=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", a+i);
        sum += a[i];
        }
    for(int i=1; i<=n; i++)
    {
        scanf("%d", b+i);
        sum2 += b[i];
    }
    if(sum >= sum2)
        puts("Yes");
    else
        puts("No");

    return 0;
}
