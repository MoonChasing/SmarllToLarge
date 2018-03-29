#include<cstdio>
#include<cstring>
const int maxn=105;
char a[maxn][maxn];
int m,n,b[maxn][maxn];
void dfs(int x,int y,int ans)
{
    if(x<0||x>=m||y<0||y>=n) return;//出界格子
    if(b[x][y]>0||a[x][y]=='*') return;//非‘@’或已经访问
    b[x][y]=ans;//连通分量编号
    for(int k=-1;k<=1;k++)//访问四周是否存在连通的格子
        for(int t=-1;t<=1;t++)
            if(k!=0||t!=0)//自身格子不需重复判断
                dfs(x+k,y+t,ans);
}
int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)&&m&&n)
    {
        int count=0;//连通块
        memset(b,0,sizeof(b));//清零
        for(i=0;i<m;i++)
            scanf("%s",a[i]);//输入数据
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(b[i][j]==0&&a[i][j]=='@')//对未访问且为‘@’的格子进行访问
                    dfs(i,j,++count);
        printf("%d\n",count);
    }
    return 0;
}
