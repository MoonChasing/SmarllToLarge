#include<cstdio>
using namespace std;

int main()
{
	long long n = 1;
	int num,ans;
	scanf("%d",&num);
	ans = num;
	for (n = 1; n <= 5000000; n++)
	{
		scanf("%d", &num);
		ans ^= num;
	}
	printf("%d",ans);
	return 0;
}