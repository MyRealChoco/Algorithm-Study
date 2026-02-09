#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 33580 (트리와 뽀미)
    solved by : minwoo0629a
*/

int n, t;
vector<int> dp;
vector<vector<int>> g;

void solve() {
    cin >> n >> t;
    g.resize(n+1); dp.resize(n+1, 0);

    int u, v;
    f(i, n-1) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int tmp;
    f(i, t) {
        cin >> tmp;

        if(i==0) dp[tmp] = 1;
        else {
            vector<int> dp_t(n+1, 0);

            for(int j=1; j<=n; j++) {
                int prev = dp[j];

                for(int &a : g[j]) prev = max(prev, dp[a]);
                dp_t[j] = prev + (j==tmp ? 1 : 0);
            }
            dp = dp_t;
        }
    }

    int re = 0;
    for(int i=1; i<=n; i++) re = max(re, dp[i]);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}