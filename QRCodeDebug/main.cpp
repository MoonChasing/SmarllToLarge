#include <iostream>
#include <cstdio>
using namespace std;

int a[1005][1005];
int b[1005][1005];
int n;

int main()
{
    scanf("%d", &n);
    int num;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &num);
            a[i][j] = b[i][j] = num;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j] == 0)
            {
                for(int k=0; k<n; k++)
                {
                    b[i][k] = 0;
                    b[k][j] = 0;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d", b[i][j] );
            if((j+1)%n)
                putchar(' ');
            else
                putchar(10);
        }
    }
    return 0;
}
