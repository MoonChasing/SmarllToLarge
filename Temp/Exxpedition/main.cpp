#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdio>
using namespace std;

int L=25, P=10, N=4;
const int MAX_N = 10;
int A[MAX_N+1] = {10,14,20,21};
int B[MAX_N+1] = {10,5,2,4};

void solve()
{
    A[N] = L;
    B[N] = 0;
    N++;

    priority_queue<int> que;

    //ans: 加油次数， pos： 现在的位置， tank: 油箱中汽油的量
    int ans = 0, pos = 0, tank = P;


    for(int i=0; i<N; i++)
    {
        //接下来要前进的距离
        int d = A[i] - pos;

        //不断加油直到油量足够到达下一个加油站
        while(tank - d < 0)
        {
            if(que.empty())
            {
                puts("-1");
                return;
            }

            tank += que.top();
            que.pop();
            ans++;
        }

        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n",ans);
}
int main()
{
    solve();
    return 0;
}
