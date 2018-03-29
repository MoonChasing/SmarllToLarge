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

const int coeff[3] = {2, 3, 5};

int main()
{
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for(int i=1; ; i++)
    {
        LL x = pq.top();
        pq.pop();

        if(i == 1500)
        {
            cout<< "The 1500'th ugly number is " << x << "." << endl;
            break;
        }

        for(int j=0; j<3; j++)
        {
            LL x2 = x * coeff[j];
            if(!s.count(x2))
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}








