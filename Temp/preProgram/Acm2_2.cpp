#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
	int address, num, next;
}Node; 

int main()
{
	int address0,n;
	int qian = 1, hou;
	int i =0,j =0;
	scanf("%d%d",&address0,&n);
	hou = n;
	Node * p =  (Node *)malloc(sizeof(Node) * n);
	
	while(n--)
	{
		scanf("%d%d%d",&p[i].address,&p[i].num, &p[i].next);
		i++;
	}
	
	for(i=0; i<n; i++)
	{
		Node t;
		for(j=i+1; j<n; j++)
		{
			if(p[i].address == address0)
			{
				t = p[i];
				p[i] = p[0];
				p[0] = t;
			}
		}
	}
	return 0;
}