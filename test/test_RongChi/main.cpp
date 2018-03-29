#include<cstdio>
#include<iostream>
#define  LL long long
#define MAXN 1000
using namespace std;

int a[MAXN];
int n,m;        //从1到n的整数中至少能整除a中一个元素的数有多少， a中有m个元素

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
            num += j&1;         //num为i的二进制中1的个数
        ll lcm = 1;

        for(int j=0; j<m; j++)
        {
            if( i >> j & 1) //如果i右移j位后为奇数
            {
                lcm = lcm / gcd(a[j], lcm) * a[j];
                //如果lcm大于n， 则n/lcm = 0. 因此在溢出之前break.
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
