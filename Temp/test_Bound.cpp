#include <iostream>
#include <cstdio>
#include <algorithm>
#define DEBUG
using namespace std;

int main()
{
    int a[10] = {12,154,521,545,12541,4,56,345,1564,18};
    sort(a, a+10);
    #ifdef DEBUG
    for(int i=0; i<=9; i++)
        printf("%d  ", a[i]);
    #endif // DEBUG
    int s = upper_bound(a, a+10,500) - a;
    putchar(10);
    printf("%d\n",s);
    return 0;
}
