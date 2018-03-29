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

char Ma[MAXN*2];
int Mp[MAXN*2];
int ans;
int Manacher(char s[], int len)
{
    int l=0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i=0; i<len; i++)
    {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;

    int mx = 0, id = 0;
    for(int i=0; i<l; i++)
    {
        Mp[i] = (mx>i) ? min(Mp[2*id-i], mx-i) : 1;    //关键点，见网址
        while(Ma[ i+Mp[i] ] == Ma[ i-Mp[i] ] )
            Mp[i]++;
        ans = max(ans, Mp[i]-1);
        if(i+Mp[i] > mx)
        {
            mx = i+Mp[i];
            id = i;
        }
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    char str[MAXN];
    gets(str);
    int len = strlen(str);
//    for(int i=0; i< 2*len+2; i++)
//        printf("%-3c", Ma[i]);
//    putchar(10);
//    for(int i=0; i< 2*len+2; i++)
//        printf("%-3d", Mp[i]);
    printf("%d\n", Manacher(str, len));
    return 0;
}

/*
    知：
        https://www.cnblogs.com/biyeymyhjob/archive/2012/10/04/2711527.html
        图见网址
    时：
        2017年8月24日 16:37:08
    地：
        学科楼215
*/









