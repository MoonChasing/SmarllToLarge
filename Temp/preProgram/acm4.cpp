#include<stdio.h>
#include<string.h>
int main()
{
	int k ,cnt = 0, i,num=0;
	char ch[100][15];
	scanf("%d",&k);
	getchar();

	for(i=1; i<100; i++)
	{
		gets(ch[i]);
		if(ch[i][0] == 'E')
			break;
		num++;
	}
	
	
	for(i=1; i<=num; i++)
	{
		if(i%(k+1) != 0)
		{
			if(ch[i][0] == 'J')
				puts("ChuiZi");
			else if(ch[i][0] == 'C')
				puts("Bu");
			else if(ch[i][0] == 'B')
				puts("JianDao");
			else 
				break;
			
		}
		else 
			puts(ch[i]);
	
	}
	
	return 0;
}