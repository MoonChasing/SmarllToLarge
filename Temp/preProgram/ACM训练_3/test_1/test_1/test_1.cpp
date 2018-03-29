#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1010;
int dp[maxn], b[maxn], w[maxn];
int tree[maxn];
vector<int> group[maxn];

int find(int x)
{
	if(tree[x] == x)
		return x;
	return tree[x] = find(tree[x]);
}

void megre(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		tree[fx] = fy;
}

int main()
{
	int n,W,m;
	while(scanf("%d%d%d",&n,&m,&W) != EOF )
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&w[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&b[i]);
		for(int i=1; i<=n; i++)
			tree[i] = i;

		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			megre(x,y);
		}
		for(int i=0; i<maxn; i++)
			group[i].clear();
		for(int i=1; i<=n; i++)
			group[find(i)].push_back(i);

		memset(dp,0,sizeof(dp));

		for(int i=1; i<=n; i++)
		{
			if( find(i) != i)
				continue;
			for(int j=W; j>=0; j--)
			{
				int sumw=0, sumb=0;
				for(int k=0; k<group[i].size();++k)
				{
					sumw += w[group[i][k]];
					sumb += b[group[i][k]];
					if(j>=w[group[i][k]])
						dp[j] = max( dp[j], dp[j - w[ group[i][k]] + b[ group[i][k] ] ] );
				}
				if(j>=sumw)
					dp[j] = max(dp[j], dp[j-sumw]+sumb);
			}
		}
		printf("%d\n",dp[W]);
	}
	return 0;
}