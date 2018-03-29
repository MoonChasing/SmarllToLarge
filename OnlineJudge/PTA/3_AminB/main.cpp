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
#define MAXN 10010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

char ch[MAXN];
set<char> st;
int main()
{
    gets(ch);
    char c;
    while((c = getchar()) != '\n')
    {
        st.insert(c);
    }
//    set<char>::iterator it;
//    for(it = st.begin(); it != st.end(); it++)
//    {
//        c = *it;
//        for(int i=0; ch[i]; i++)
//        {
//            if(ch[i] == c)
//                ch[i] = 10;
//        }
//    }

//    bool exist;
    for(int i=0; ch[i]; i++)
    {
        if(st.find(ch[i]) == st.end())
            putchar(ch[i]);
    }
    putchar(10);
    return 0;
}



