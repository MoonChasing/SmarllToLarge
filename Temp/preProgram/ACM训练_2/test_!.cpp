#include<cstdio>
#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;



const int  INF = 10000000;
char maze[MAX_N][MAX_M+1];
typedef pair<int, int> P;
int N,M;
int minute;
int sx,sy;
int gx,gy;

int d[MAX_N][MAX_M];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<char> keys;

void init()
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			 maze[i][j] = getchar();
		getchar();
	}

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			if(maze[i][j] == '@')
			{
				sx = i;
				sy = j;
			}
			if(maze[i][j] == '^')
			{
				gx = i;
				gy = j;
			}
		}
	}
	
}

bool if_exist(char ch)
{
	vector<char>::iterator it = find(keys.begin(),keys.end(),ch);
	if(it == keys.end())
		return false;
	else
		return true;
}

int bfs()
{
	queue<P> que;

	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			d[i][j] = INF;
	que.push(P(sx,sy));
	d[sx][sy] = 0;

	while(que.size())
	{
		P p = que.front();
		que.pop();

		if(p.first == gx && p.second == gy)
			break;

		for(int i=0; i<4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if(0 <= nx && nx < N && 0<= ny && ny<M && (maze[nx][ny] != '*' || !if_exist(maze[nx][ny]+32)) && d[nx][ny] == INF)
			{
				if(maze[nx][ny] >= 'a' && maze[nx][ny]<= 'j')
					keys.push_back(maze[nx][ny]);

				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}

	}

	return d[gx][gy];
}



int main()
{
	while(scanf("%d%d%d",&N,&M,&minute))
	{
		init();
		int time = bfs();
		if( time < minute )
			printf("%d\n",time);
		else
			printf("-1");
		getchar();
		getchar();
	}
	
	return 0;
}

