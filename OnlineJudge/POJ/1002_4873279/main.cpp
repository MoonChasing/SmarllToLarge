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
#define MAXN 100010
#define INF 0x3f3f3f3f
#define DEBUG
#define DataIn
typedef long long LL;

using namespace std;

int T;
int alpha2num[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9};

char buf[128];
map<int, int> mp;

int main()
{
    scanf("%d", &T);
    bool flag = false;
    while(T--)
    {
        scanf("%s", buf);
        int ans = 0;
        for(int i=0; buf[i]; i++)
        {
            if( isdigit(buf[i]) )
                ans = ans * 10 + buf[i] - 48;
            else if( isalpha(buf[i]) )
                ans = ans * 10 + alpha2num[buf[i]-'A'];
        }
        mp[ans]++;
    }
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if(it->second > 1)
        {
            flag = true;
            printf("%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second);
        }
    }
    if(!flag)
        puts("No duplicates.");
    return 0;
}











