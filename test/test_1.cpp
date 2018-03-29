#include <iostream>
#define MAXN 1e5    //这么定义MAXN，下面数组不可以写a[MAXN]，理由好像是因为这么写MAXN为double值。
using namespace std;

const int MAXN = 1e5;
int a[MAXN];
int main()
{
    cout << MAXN << endl;
    return 0;
}

/*
    time：2017年8月13日 12:35:45
    test：近来定义数组时经常报错，故作此测试，知其原由。
    place：学科楼215
 */
