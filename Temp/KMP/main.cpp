#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 150
int next[MAXN];

void kmp_pre(char x[], int m, int next[])
{
    int i,j;
    j = next[0] = -1;
    i = 0;

    while(i<m)
    {
        while(-1 != j && x[i] != x[j])
            j = next[j];
        next[++i] = ++j;
    }
}

int KMP_Count(char x[],int m,char y[],int n)
{
    //x是模式串， y是主串
    int i,j;
    int ans=0;
    //preKMP(x,m,next);
    kmp_pre(x,m,next);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])
            j=next[j];
        i++;
        j++;
        if(j>=m)
        {
            ans++;
            j = 0;
        }
    }
    return ans;
}

int main()
{
    cout << "Hello world!" << endl;
    char str1[20] = "abababababa";
    char str2[5] = "aba";
    int cnt = KMP_Count(str2, strlen(str2), str1, strlen(str1));
    printf("%d\n",cnt);
    return 0;
}
