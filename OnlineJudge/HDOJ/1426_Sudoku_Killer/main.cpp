#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF  0x3f3f3f3f

using namespace std;

typedef long long  LL;
typedef pair<int,int> P;
P node[90];
int sd[10][10],f=0,cnt;

bool jud(int x,int y,int k)
{
    for(int i=0; i<9; ++i) //�ж��к���
    {
        if(sd[i][y]==k)return false;
        if(sd[x][i]==k)return false;
    }
    int tmpx=(x/3)*3,tmpy=(y/3)*3;
    for(int i=tmpx; i<tmpx+3; ++i) //�жϾŹ���
    {
        for(int j=tmpy; j<tmpy+3; ++j)
        {
            if(sd[i][j]==k)return false;
        }
    }
    return true;
}

void dfs(int n)
{
    if(f)
        return;
    if(n==cnt)
    {
        f=1;
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                printf("%d%c",sd[i][j],j==8?'\n':' ');
            }
        }
        return;
    }
    for(int i=1; i<=9; ++i)
    {
        if(jud(node[n].first,node[n].second,i))
        {
            sd[node[n].first][node[n].second]=i;
            dfs(n+1);
        }
        if(f)
            return;//�ҵ�������˳�����
    }
    sd[node[n].first][node[n].second]=0;//ѭ������Ҳû�н⣬˵����״̬�޽⣬�˻�0
}

int main()
{
    char s[5];
    int i,j;
    while(~scanf("%s",s)) //scanf�Զ����Իس������Բ��ô�������֮��Ŀ���
    {
        cnt=0;
        sd[0][0]=(s[0]=='?'?0:s[0]-'0');//�����һ�е�һλ
        for(i=1; i<9; ++i)
        {
            scanf("%s",s);
            sd[0][i]=(s[0]=='?'?0:s[0]-'0');//��һ�к����λ
        }
        for(i=1; i<9; ++i)
        {
            for(j=0; j<9; ++j)
            {
                scanf("%s",s);
                sd[i][j]=(s[0]=='?'?0:s[0]-'0');//�������
            }
        }
        for(int i=0; i<9; ++i) //��¼û�����λ��
        {
            for(int j=0; j<9; ++j)
            {
                if(!sd[i][j])
                    node[cnt].first=i,node[cnt++].second=j;
            }
        }
        if(f)putchar('\n');//�����֮���пո�
        f=0;
        dfs(0);
    }
}
