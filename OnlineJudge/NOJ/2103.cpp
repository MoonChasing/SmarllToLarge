#include<cstdio>
#include<cstring>

using namespace std;
#define MAXN 15
char num[MAXN];
int main()
{
    int kase;
    scanf("%d",&kase);
    getchar();

    while(kase--)
    {
        int sum =0;
        gets(num);
        int len = strlen(num);
        for(int i=0; i<len; i++)
        {
            sum += num[i] - 48;
        }
        printf("%d\n",sum);
    }
    return 0;
}
