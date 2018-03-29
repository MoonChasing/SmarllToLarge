#include<cstdio>

using namespace std;

int main()
{
    int i;
    // while(~scanf("%d",&i))
    //     printf("%d\n",i&(i-1));

    for(int i=1; i<=100; i++)
    {
        printf("%3d: %d\n",i, i&i-1);
    }
    // for(i=1; i<=100; i++)
    //     printf("%d\n",i^1);

    // printf("%d\n",3^8);
     getchar();
    return 0;
}

/*
    i&(i-1)值为i或i-1中的偶数 //error
    2017年8月18日 19:07:10 更正
    i&(i-1)可判断i是否为2的幂次，是的值为0， 不是的话我也不知道值是啥
    i^1值为 奇数-1，偶数+1
 */
