#include<cstdio>
#include<iostream>
#define  LL long long
#define MAXN 1000
using namespace std;

int a[MAXN];
int n,m;        //��1��n������������������a��һ��Ԫ�ص����ж��٣� a����m��Ԫ��

int gcd(int a, int b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}
void solve()
{
    ll res = 0;
    for(int i=1; i < (1<<m); i++)
    {
        int num = 0;

        for(int j=i; j!=0; j>>1)
            num += j&1;         //numΪi�Ķ�������1�ĸ���
        ll lcm = 1;

        for(int j=0; j<m; j++)
        {
            if( i >> j & 1) //���i����jλ��Ϊ����
            {
                lcm = lcm / gcd(a[j], lcm) * a[j];
                //���lcm����n�� ��n/lcm = 0. ��������֮ǰbreak.
                if(lcm > n)
                    break;
            }
        }
        if(num % 2 == 0)
            res -= n/lcm;
        else
            res += n/lcm;
    }
}
int main()
{

    return 0;
}
