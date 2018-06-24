#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 1000000007
#define mod(x) (x%MOD)

LL n;
int ans[] = { 1, 5, 11, 36 };

struct node {
    LL arr[4][4];

    node() {}
    node( LL a[][4] ) {
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j ) {
                arr[i][j] = a[i][j];
            }
        }
    }

    node operator*( node a ) {
        node res;
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j ) {
                LL t = 0;
                for( int k = 0; k < 4; ++k ) {
                    t += this->arr[i][k] * a.arr[k][j];
                    t = mod( t );
                }
                res.arr[i][j] = t;
            }
        }

        return res;
    }

    void init() {
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j ) {
                if( i == j ) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }
            }
        }
    }

    void show() {
        for( int i = 0; i < 4; ++i ) {
            for( int j = 0; j < 4; ++j ) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

node cal( node a, int m ) {
    node res;
    res.init();
    while( m ) {
        if( (m&1) ) {
            res = res * a;
        }
        a = a * a;
        m /= 2;
    }
    return res;
}

int main() {
    while( scanf( "%lld", &n ) != EOF ) {
        if( n <= 4 ) {
            printf( "%d\n", ans[n-1] );
            continue;
        }
        LL tmp[][4] = { {1,5,1,-1}, {1,0,0,0}, {0,1,0,0}, {0,0,1,0} };
        node a(tmp);
        a = cal( a, n-4 );
//        a.show();
        LL _t = 0;
        for( int i = 0; i < 4; ++i ) {
            _t += ans[3-i] * a.arr[0][i];
            _t = mod( _t );
        }
        printf( "%lld\n", _t );
//        cout<<_t<<endl;
    }
}
