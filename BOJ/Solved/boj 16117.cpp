#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16117 (실버런)
    solved by : minwoo0629a
*/

int n, m;
int dx[3] = {1, 1, 2};
int dy[3] = {-1, 1, 0};
vector<vector<int>> v, dp, dp_d;

void solve() {
    cin >> n >> m;
    v.resize(n+1, vector<int>(m+1, 0)); dp.resize(n+1, vector<int>(m+2, 0)); dp_d.resize(n+1, vector<int>(m+2, 0));
    
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> v[i][j];

    int mx, tmp;
    for(int x=m; x>-1; x--) {
        for(int y=0; y<=n; y++) {
            mx = 0;
            f(i, 3) {
                int xt = x + dx[i];
                int yt = y + dy[i];

                if(xt<0 || yt<0 || xt>m+1 || yt>n) continue;

                tmp = dp[yt][xt];
                if(i==2) tmp += v[yt][xt-1];
                if(tmp > mx) mx = tmp;
            }
            dp[y][x] = mx + v[y][x];
        }
    }
    for(int x=m; x>=1; x--) {
        for(int y=0; y<=n; y++) {
            mx = 0;
            
            if(y!=n) {
                tmp = v[y+1][x];
                if(x<m && y+1 < n) tmp += dp_d[y+1][x+1];
                mx = max(mx, tmp);
            }
            if(y>0) {
                tmp = v[y][x];
                if(x<m) tmp += dp_d[y-1][x+1];
                mx = max(mx, tmp);
            }

            dp_d[y][x] = mx;
        }
    }

    mx = 0;
    f(i, n+1) mx = max(mx, dp[i][0]);
    f(i, n+1) mx = max(mx, dp_d[i][1]);
    cout << mx;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}