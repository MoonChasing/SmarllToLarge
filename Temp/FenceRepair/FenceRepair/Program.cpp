#include<cstdio>

using namespace std;
typedef long long LL;

int N = 3;
int L[3] = {8,5,8};

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void solve()
{
	LL ans = 0;

	while (N > 1)
	{
		int mii1 = 0, mii2 = 1;
		if (L[mii1] > L[mii2])
			swap(mii1, mii2);
		
		for (int i = 2; i < N; i++)
		{
			if (L[i] < L[mii1])
			{
				mii2 = mii1;
				mii1 = i;
			}
			if (L[i] < L[mii2])
			{
				mii2 = i;
			}
		}

		int t = L[mii1] + L[mii2];
		ans += t;
		
		if (mii1 == N - 1)
			swap(mii1,mii2);
		L[mii1] = t;
		L[mii2] = L[N - 1];
		N--;
	}
	printf("%lld\n",ans);
	getchar();
}
int main()
{
	solve();
	return 0;
}

