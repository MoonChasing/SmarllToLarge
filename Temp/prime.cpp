#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1000010;
bool notprime[MAXN];
int prime[MAXN+1];

//��ͨɸѡ��ʱ�临�Ӷ�O(nloglogn)
void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int i=2; i<MAXN; i++)
    {
        if(!notprime[1])
        {
            if(i < MAXN / i)
                continue;
            for(int j= i*i; j<MAXN; j+=i)
                notprime[j] = true;
        }
    }
}

//����ɸѡ O(n)
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for(int i=2; i<=MAXN; i++)
    {
        if(!prime[i])
            prime[++prime[0]] = i;
        for(int j=1; j<prime[0] && prime[j] < MAXN/i; j++)
        {
            prime[prime[j]*i] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    init();
    return 0;
}



/*
    �ջ�
        ��˵100W�����������£� ��ͨɸ��Ҫ��������ɸ��
    ʱ�䣺
        2018��2��11�� 23:41:52
    �ص㣺
        ���в輸
*/
