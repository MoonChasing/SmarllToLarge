#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
		int n,m;
		vector<int> book;
		int weight[501], order[1001], sta[501] = {0};
		int i;
		int sum = 0;

		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&weight[i]);
		for(i=0;i<m;i++)
		{	
			scanf("%d",&order[i]);
			
			if(sta[order[i]] == 0)
			{
				book.push_back(order[i]);
				sta[order[i]] = 1;
			}
			
		}
		for(i=0; i<m; i++)
		{
			int p = 0;
			while(book.at(p) != order[i])
			{
				sum+=weight[book.at(p)];
				p++;				
			}

			vector<int>::iterator it = book.begin() + p;
			book.erase(it);
			book.insert(book.begin(),order[i]);
		}
		cout<<sum;	
        return 0;
}