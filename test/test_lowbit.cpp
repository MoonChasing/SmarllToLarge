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
�ĵã�
    a&-a�õ��Ľ��Ϊa��������ͷ�0λ�������ֵ
    ��8������Ϊ1000�� ���λ��1����8
      6������Ϊ110�� ���λ��1����2
ʱ�䣺
    2017��8��14�� 14:57:46
�ص㣺
    ѧ��¥215
*/
