#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5535 (패셔니스타)
    solved by : minwoo0629a
*/

int d, n, dp[201][201];
vector<int> temp;
vector<tuple<int, int, int>> cl;

void solve() {
    cin >> d >> n;
    temp.resize(d);
    f(i, d) cin >> temp[i];

    int a, b, c;
    f(i, n) {
        cin >> a >> b >> c;
        cl.emplace_back(a, b, c);
    }

    memset(dp, -1, sizeof(dp));
    f(i, n) {
        auto[l, h, c] = cl[i];
        if(temp[0] >= l && temp[0] <= h) dp[0][i] = 0;
    }

    for(int i=1; i<d; i++) {
        for(int j=0; j<n; j++) {
            auto[l, h, c] = cl[j];

            if(temp[i] < l || temp[i] > h) continue;

            f(k, n) {
                if(dp[i-1][k] != -1) {
                    auto[l_b, h_b, c_b] = cl[k];
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(c - c_b));
                }
            }
        }
    }

    int re = 0;
    f(i, n) {
        if(dp[d-1][i] != -1) re = max(re, dp[d-1][i]);
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}