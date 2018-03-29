#include<cstdio>
#include<map>

using namespace std;

map<int, int> a;

int main()
{
	int num;
	long long n = 1;
	while ( n <= 5000001 &&scanf("%d", &num) )
	{
		if (!a.count(num))
		{
			a.insert(map<int, int>::value_type(num, 1));
		}
		else if (a[num] == 1)
			a.erase(num);
		n++;
	}
	//printf("%d\n",a.size());
	map<int, int>::iterator it;
	for(it = a.begin(); it != a.end(); it++)
		printf("%d",it->first);
	return 0;
}