#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a;
    while(true)
    {
        scanf("%d",&a);
        printf("%d\n", a&-a);
    }
    return 0;
}

/*
心得：
    a&-a得到的结果为a二进制最低非0位所代表的值
    如8二进制为1000， 最低位的1代表8
      6二进制为110， 最低位的1代表2
时间：
    2017年8月14日 14:57:46
地点：
    学科楼215
*/
