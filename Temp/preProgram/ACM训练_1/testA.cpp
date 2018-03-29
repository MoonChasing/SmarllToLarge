#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int max(int a,int b)
{
	return a>b? a : b;
}
int main(void)
{
	int n,m;
	const int maxsize = 101;
	int i,j,k;
	int a[maxsize][maxsize];
	int f[maxsize];
	
	while(scanf("%d%d",&n,&m), n+m)
	{
		for(i=0;i<=m;++i)
			f[i]=0;  
		
        for(i=0;i<n;++i)  
            for(j=1;j<=m;++j)
				scanf("%d",&a[i][j]);  
			
			for(i=0;i<n;++i)  
				for(j=m;j>=0;--j)  
					for(k=1;k<=j;++k)	
						f[j]=max(f[j],f[j-k]+a[i][k]);  
					printf("%d\n",f[m]); 
	}
	return 0;
}