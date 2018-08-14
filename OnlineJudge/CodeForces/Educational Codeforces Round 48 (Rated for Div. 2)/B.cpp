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
#define MAXN 1010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int next[MAXN];

char s[MAXN], t[MAXN];
int lens, lent;

void prekmp(char x[], int m)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i < m)
    {
        while(j!=-1 && x[i]!=x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int kmpcount(char x[], int m, char y[], int n)
{
    int i,j;
    int ans=0;
    i = j = 0;
    while(i<n)
    {
        while(-1 != j && y[i] != x[j])
            j = next[j];
        i++; j++;
        if(j >= m)
        {
            ans++;
            j=next[j];  // j = next[j]为计数可以重叠， j = 0为计数不重叠
        }
    }
    return ans;
}

int main()
{
    int q;
    scanf("%d%d%d", &lens, &lent, &q);
    scanf("%s%s", s, t);
    int l, r, len;

    prekmp(t, lent);

    while(q--)
    {
        scanf("%d%d", &l, &r);
        len = r-l+1;
        printf("%d\n",kmpcount(t, lent, s+l-1, len));
    }
    return 0;
}











