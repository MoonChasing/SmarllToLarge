#include<stdio.h>
#include<stdlib.h>
int main()
{
	int row,col,i,j;
	scanf("%d%d",&row,&col);
	int ** a = (int **)malloc(sizeof(int *) * row);
	for(i=0; i<row;i++)
		a[i] = (int *) malloc(sizeof(int) * col);
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",&a[i][j]);
		
		
		int row2,col2;
		scanf("%d%d",&row2,&col2);
		int ** b = (int **)malloc(sizeof(int *) * row);
		for(i=0; i<row;i++)
			b[i] = (int *) malloc(sizeof(int) * col);
		
		for(i=0;i<row2;i++)
			for(j=0;j<col2;j++)
				scanf("%d",&b[i][j]);
			
			if(col!=row2)
				printf("Error: %d != %d", col, row2);
			else
			{
				int sum =0,  count = 0,m,n;
				printf("%d %d\n",row,col2);
				
				
					for(m=0;m<row;m++)
					{
						for(n=0;n<col2;n++)
						{
							for(i=0;i<col;i++)
							{
								for(j=0;j<row2;j++)
									sum+=a[m][i]*b[n][j];

								printf("%d",sum);
							}
									
						}
						putchar(10);
					}
				
			}
			return 0;
}

