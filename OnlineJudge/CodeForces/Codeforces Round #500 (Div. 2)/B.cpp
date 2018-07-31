#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int b[MAXN<<1];

int main()
{
    int ans = 0;
    int n,x;
    scanf("%d%d", &n, &x);

    memset(b, -1, sizeof(b));

    bool flag = false;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &b[i]);
        if(find(b, b+i, b[i]) != b+i) //bÖÐ
            flag = true;
    }

    if(flag)
    {
        puts("0");
        return 0;
    }

    bool can = false;
    for(int i=0; i<n; i++)
    {
        if( (b[i]&x) != b[i] )
            can = true;
    }

    if( !can )
    {
        puts("-1");
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        b[n+i] = b[i] & x;
        if( find(b, b+n, b[i+n]) != b+n)
        {
            printf("1\n");
            return 0;
        }
    }

    printf("2\n");
    return 0;
}
