#include<stdio.h>

int main()
{
	int i=0,d;
	int ch;
	int a[1000010];

	while(scanf("%d",&d) == 1)
	{
		ch = getchar();
		if(ch == 10)
			break;
		a[i] = d;
		i++;
	}

	for(i = 0; i<1000010; i++)
	{
		if(a[i] == 250)
			break;
	}

	printf("%d",i+1);
	return 0;
}