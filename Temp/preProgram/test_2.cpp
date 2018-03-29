#include<stdio.h>

int main(void)
{
	int a;
	FILE *fp = fopen("G:\\HelloWorld\\C\\Debug\\1.txt","r");
	a= fscanf(fp,"%d",&a);
	printf("%d",a);
	fclose(fp);
	return 0;
}