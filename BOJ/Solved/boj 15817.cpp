#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 15817 (배수 공사)
    solved by : minwoo0629a
*/

int n, x;
vector<pair<int, int>> v;
vector<vector<int>> dp;

void solve() {
    cin >> n >> x;
    dp.resize(n+1, vector<int>(x+1, 0));
    int l, c;
    f(i, n) {
        cin >> l >> c;
        v.emplace_back(l, c);
    }

    dp[0][0] = 1;
    for(int i=1; i<=n; i++) {
        auto &[l, c] = v[i-1];

        f(j, x+1) {
            f(k, c+1) {
                if(j - l*k < 0) break;
                dp[i][j] += dp[i-1][j - l*k];
            } 
        }
    }

    cout << dp[n][x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}