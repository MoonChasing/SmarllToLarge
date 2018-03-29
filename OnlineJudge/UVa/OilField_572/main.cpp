#include<cstdio>
#include<cstring>
const int maxn=105;
char a[maxn][maxn];
int m,n,b[maxn][maxn];
void dfs(int x,int y,int ans)
{
    if(x<0||x>=m||y<0||y>=n) return;//�������
    if(b[x][y]>0||a[x][y]=='*') return;//�ǡ�@�����Ѿ�����
    b[x][y]=ans;//��ͨ�������
    for(int k=-1;k<=1;k++)//���������Ƿ������ͨ�ĸ���
        for(int t=-1;t<=1;t++)
            if(k!=0||t!=0)//������Ӳ����ظ��ж�
                dfs(x+k,y+t,ans);
}
int main()
{
    int i,j;
    while(scanf("%d%d",&m,&n)&&m&&n)
    {
        int count=0;//��ͨ��
        memset(b,0,sizeof(b));//����
        for(i=0;i<m;i++)
            scanf("%s",a[i]);//��������
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(b[i][j]==0&&a[i][j]=='@')//��δ������Ϊ��@���ĸ��ӽ��з���
                    dfs(i,j,++count);
        printf("%d\n",count);
    }
    return 0;
}
