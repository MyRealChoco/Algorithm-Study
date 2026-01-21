#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 34846 (이웃 마을)
    solved by : minwoo0629a
*/

int n, m, q;
vector<vector<int>> g;
vector<bool> s;
vector<int> dp;

void solve() {
    int a, b;
    cin >> n >> m >> q;
    g.resize(n+1); s.resize(n+1, 0), dp.resize(n+1, 0);

    f(i, m) {
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    while(q--) {
        cin >> a >> b;
        if(a == 1) {
            if(!s[b]) {
                for(int idx : g[b]) dp[idx]++;
                s[b] = true;
            }
        }
        else cout << dp[b] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}