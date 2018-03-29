#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 200000 + 5;

int vis[MAXN], x[MAXN];

int main(){
    int n, k, a, m, l, r, cur, ans;
    while(scanf("%d %d %d", &n, &k, &a) != EOF){
        scanf("%d", &m);
        for(int i=0; i<m; ++i){
            scanf("%d", &x[i]);
        }
        memset(vis, 0, sizeof(vis));
        ans = -1;
        cur = (n + 1)/(a+1);
        for(int i=0; i<m; ++i){
            vis[ x[i] ] = 1;
            l = x[i]-1; r = x[i]+1;
            while(l >=1 && vis[l] == 0){
                l--;
            }
            while(r <= n && vis[r] == 0){
                r++;
            }
            cur -= (r-l)/(a+1) - (r-x[i])/(a+1) - (x[i]-l)/(a+1);
            if(cur < k){
                ans = i + 1;
                break;
            }
        }
        printf("%d\n", ans );
    }
    return 0;
}
