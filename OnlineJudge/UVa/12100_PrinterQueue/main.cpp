#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<cctype>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;
int gcd(int a, int b){return b==0?a:gcd(b,a%b);}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int q[150];
		int front = 0, rear = 0;
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			q[rear++] = x;
		}
		while(1)
		{
			int x = q[front];
			bool flag = false;
			int i;
			for(i = (front + 1) % 150; i != rear; i = (i + 1) % 150)
			{
				if(q[i] > x)
				{
					flag = true;
					break;
				}
			}
			if(flag)
			{
				if(m == front)
					m = rear;
				front = (front + 1) % 150;
				q[rear] = x;
				rear = (rear + 1) % 150;
			}
			else
			{
				ans++;
				if(m == front)
				{
					printf("%d\n", ans);
					break;
				}
				front = (front+1)%150;
			}
		}
	}
	return 0;
}
