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
#define MAXN 200005
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n, w;
int a[MAXN], b[MAXN];
int next[MAXN];

void prekmp()
{
    int i=0, j=-1;
    next[0] = -1;
    while(i<w)
    {
        while(~j && b[i]!=b[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int kmpcnt()
{
    int i=0, j=0;
    int cnt = 0;
    prekmp();
    while(i<n)
    {
        while(~j && a[i]!=b[j])
            j = next[j];
        i++; j++;
        if(j >= w)
        {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}

int main()
{
    n = read(), w = read();
    for(int i=0; i<n; i++)
        a[i] = read();
    for(int i=n-1; i>0; i--)
        a[i] -= a[i-1];
    for(int i=0; i<n-1; i++)
        a[i] = a[i+1];
//    for(int i=0; i<n-1; i++)
//        printf("%d ", a[i])
//    putchar(10);
    n--;

    for(int i=0; i<w; i++)
        b[i] = read();
    for(int i=w-1; i>0; i--)
        b[i] -= b[i-1];
    for(int i=0; i<w-1; i++)
        b[i] = b[i+1];
    w--;
    if(w==0)//子中长度为1时要特判
        printf("%d\n", n+1);
    else
        printf("%d\n", kmpcnt());
    return 0;
}















