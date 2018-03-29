#include<stdio.h>
#include<string.h>

int main()
{
	int n,a,b,num=0,i=0;
	char name[5];
	char ans[10000][5];
	scanf("%d",&n);
	
	while(n--)
	{
		scanf("%s%d%d",name,&a,&b);
		getchar();
		if(a<15 || a>20 || b<50 || b>70)
		{
			strcpy(ans[i],name);
			i++;
			num++;
		}
	}

	for(i=0; i<num; i++)
		puts(ans[i]);
	return 0;
} 