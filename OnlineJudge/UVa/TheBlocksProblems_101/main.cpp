#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define MAXN 30
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int n;
vector<int> pile[MAXN];

void findblock(int a, int & p, int & h)
{
   for(p=0; p<n; p++)
       for(h=0; h<pile[p].size(); h++)
           if(pile[p][h] == a)
               return;
}

void clearabove(int p, int h)
{
   for(int i=h+1; i<pile[p].size(); i++)
   {
       int b = pile[p][i];
       pile[b].push_back(b);
   }
   pile[p].resize(h+1);
}

void pile_onto(int p, int h, int p2)
{
   for(int i=h; i<pile[p].size(); i++)
       pile[p2].push_back(pile[p][i]);
   pile[p].resize(h);
}

void print()
{
   for(int i=0; i<n; i++)
   {
       printf("%d:",i);
       for(int j=0; j<pile[i].size(); j++)
           printf(" %d", pile[i][j]);
       putchar(10);
   }
}

int main()
{
   int a,b;
   cin>>n;
   string s1, s2;
   for(int i=0; i<n; i++)
       pile[i].push_back(i);
   while(cin >> s1 >> a >> s2 >> b)
   {
       int pa, pb, ha, hb;
       findblock(a, pa, ha);
       findblock(b, pb, hb);

       if(pa == pb)
           continue;
       if(s2 == "onto")
           clearabove(pb, hb);
       if(s1 == "move")
           clearabove(pa, ha);
       pile_onto(pa, ha, pb);
   }
   print();
   return 0;
}




