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

bool vis[30];
vector<char> q;
char str[205];

int main()
{
    int ans = 0;
    int len;

    scanf("%d", &len);
    getchar();
    gets(str);
    memset(vis, false, sizeof(vis));

    for(int i=0; i<len; i++)
    {
        if(str[i]>='a' && str[i]<='z' && !vis[str[i] - 'a'])
        {
            q.push_back(str[i]);
            vis[str[i]-'a'] = true;
        }
        if(str[i]>='A' && str[i]<='Z')
        {
            ans = max(ans, (int)q.size());
            q.clear();
            memset(vis, false, sizeof(vis));
        }
    }
    ans = max(ans, (int)q.size());
    printf("%d\n", ans);
    return 0;
}











