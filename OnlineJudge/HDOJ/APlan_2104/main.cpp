#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

struct point{
    int x,y,step,type;
}   P[105];
char mp[2][12][12];
int M,N,T,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int bfs(point X)
{
    point t,tt;
    queue<point> Q;
    Q.push(X);
    while(!Q.empty())
    {
        t=Q.front();
        Q.pop();
        if(mp[t.type][t.x][t.y]=='*')   continue;
        if(mp[t.type][t.x][t.y]=='P')   return 1;
        mp[t.type][t.x][t.y]='*';
        for(int i=0;i<4;i++){
            tt.x=t.x+dir[i][0];tt.y=t.y+dir[i][1];tt.step=t.step+1;tt.type=t.type;
            if(tt.step>T||mp[tt.type][tt.x][tt.y]=='*')  continue;

            if(mp[tt.type][tt.x][tt.y]=='#'){               //如果是#
                mp[tt.type][tt.x][tt.y]=='*';               //变为*
                tt.type=1-tt.type;                          //传送到另一层
                if(mp[tt.type][tt.x][tt.y]=='#'||mp[tt.type][tt.x][tt.y]=='*'){         //忽略
                    mp[tt.type][tt.x][tt.y]=mp[1-tt.type][tt.x][tt.y]='*';          //变为*
                    continue;                               //换个方向
                }
            }
            Q.push(tt);
        }
    }
    return 0;
}

int main()
{
    int i,j,C;
    point S;
    scanf("%d",&C);
    while(C--)
    {
        memset(mp,'*',sizeof(mp));
        cin>>M>>N>>T;
        for(i=1;i<=M;i++)    for(j=1;j<=N;j++)    cin>>mp[0][i][j];
        for(i=1;i<=M;i++)    for(j=1;j<=N;j++)    cin>>mp[1][i][j];

        S.x=1;S.y=1;S.step=0;S.type=0;

        if(bfs(S))  printf("YES\n");
        else        printf("NO\n");
    }
    return 0;
}
