#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int maxn = 1e5+5;
char s[maxn];
LL A[maxn], B[maxn];
int a,b;
int l;

int main()
{
	scanf("%s%d%d",s,&a,&b);
	l = strlen(s);
	LL p;
	int i,j;

	A[0]=(s[0]-48)%a;  
    for(i=1;i<l;++i)
		A[i]=(A[i-1]*10+s[i]-48)%a;  

    B[l-1]=(s[l-1]-48)%b;  
    for(i=l-2,p=1;i>=0;--i){  
        p=p*10%b;  
        B[i]=(B[i+1]+(s[i]-48)*p)%b;  
    }  
    bool flag=0;  
    for(i=0;i<l;++i)  
        if(A[i]==0 && i+1<l && s[i+1]!='0' &&B[i+1]==0)
		{  
            flag=1;
			break;  
        }  

    if(flag){  
        puts("YES");  
        for(j=0;j<=i;++j) 
			printf("%c",s[j]);  
        putchar(10);
		for(j=i+1;j<l;++j) 
			printf("%c",s[j]);  
    }  
    else 
		puts("NO"); 
	return 0;
}