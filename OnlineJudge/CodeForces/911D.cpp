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
#define MAXN 1505
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int a[MAXN];
int n, m;
int main()
{
    int all = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
            if(a[i] > a[j])
                all++;
    }

    bool isodd = false;
    if(all & 1)
        isodd = true;

    int l, r, len;
    scanf("%d", &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &l, &r);
        len = r-l+1;
        if((len * (len-1) / 2) & 1)
            isodd = !isodd;
        if(isodd)
            puts("odd");
        else
            puts("even");
    }
    return 0;
}












