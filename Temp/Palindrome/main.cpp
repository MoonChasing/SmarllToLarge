#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX = 1000010;
int len, p[2*MAX];
char str[2*MAX], newstr[2*MAX];
int casecnt;

void change()
{
     int i;
     newstr[0] = '@';
     newstr[1] = '#';
     for (i = 0; i < len; i++){
         newstr[2*i + 2] = str[i];
         newstr[2*i + 3] = '#';
     }
     newstr[2*len + 2] = '\0';
     return ;
}


void Manacher()
{
     int i, j, id, maxid = 0, ans = 1;
     len = 2 * len + 2;
     for (i = 0; i < len; i++){
         if (maxid > i){
             p[i] = min(p[2*id - i], maxid - i);
         }
         else{
              p[i] = 1;
         }
         while (newstr[i+p[i]] == newstr[i-p[i]])
                p[i]++;
         if (p[i] + i > maxid){
             maxid = p[i] + i;
             id = i;
         }
         if (ans < p[i])
             ans = p[i];
     }

     for (i = id, j = 0; i < id + ans; i++){
          if (newstr[i] != '#'){
              str[j] = newstr[i];
              j++;
          }
     }
     str[id+ans] = '\0';
     printf("Case %d: %d\n", ++casecnt, ans-1);
     return ;
}


int main()
{
    while (scanf("%s", str)){
          if (strcmp(str, "END") == 0)   break;
          len = strlen(str);
          change();
          Manacher();
    }
}
