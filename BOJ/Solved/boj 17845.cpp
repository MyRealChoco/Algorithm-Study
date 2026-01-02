#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17845 (수강 과목)
    solved by : minwoo0629a
*/

int n, k;
vector<pair<int, int>> v;

void solve() {
    cin >> n >> k;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    v.resize(k);

    f(i, k) cin >> v[i].first >> v[i].second;
    
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            if(v[i-1].second > j) dp[j][i] = dp[j][i-1];
            else dp[j][i] = max(dp[j][i-1], v[i-1].first + dp[j - v[i-1].second][i-1]);
        }
    }
    cout << dp[n][k];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}