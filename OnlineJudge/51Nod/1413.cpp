#include<cstdio>
#include<cstring>
using namespace std;

char num[10];

int main()
{
    gets(num);
    int len = strlen(num);
    int ans = 0;
    for(int i=0; i<len; i++)
    {
        int a = num[i]-'0'-i;
        if(a>0)
            ans += a;
    }
    printf("%d\n",ans);
    return 0;
}
