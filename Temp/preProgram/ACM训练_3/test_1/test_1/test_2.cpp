#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <cmath>  
#define LL long long  
using namespace std;  
LL a[300000];  
LL b[300000];  
LL c[300000];  
int main(){  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<n;i++){  
        scanf("%I64d",&a[i]);  
    }  
    a[n]=0;  
    for(int i=0;i<n;i++){  
        b[i]=abs(a[i]-a[i+1]);  
        if(i&1)  
            b[i]=-b[i];  
        c[i]=-b[i];  
    }  
    LL sum=0,mic=0;  
    for(int i=0;i<n-1;i++){  
        sum+=b[i];  
        if(sum<0){  
            sum=0;  
        }  
        mic=max(mic,sum);  
    }  
    sum=0;  
    for(int i=0;i<n-1;i++){  
        sum+=c[i];  
        if(sum<0){  
            sum=0;  
        }  
        mic=max(mic,sum);  
    }  
    mic=max(sum,mic);  
    cout<<mic<<endl;  
	
    return 0;  
}  