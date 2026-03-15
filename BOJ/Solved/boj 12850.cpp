#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 12850 (본대 산책2)
    solved by : minwoo0629a
*/

const int mod = 1000000007;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

vvl adj = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

vvl operator *(vvl &a, vvl &b) {
    vvl c(8, vl(8));
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            for(int k=0; k<8; k++){
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vvl div_mul(int d, vvl &m) {
    if(d==1) return m;

    vvl tmp;
    if(d%2) {
        tmp = div_mul(d-1, m);
        return tmp*m;
    } else {
        tmp = div_mul(d/2, m);
        return tmp * tmp; 
    }
}

void solve() {
    int d;
    cin >> d;
    vvl ans = div_mul(d, adj);

    cout << ans[0][0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}