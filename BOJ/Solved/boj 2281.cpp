#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 2281 (데스노트)
    solved by : minwoo0629a
*/

int n, m;
vector<int> v, pref;

int checkLine(int i, int j) {
    return pref[j] - pref[i-1] + j - i;
}

void solve() {
    cin >> n >> m;
    v.resize(n+1); pref.resize(n+1);
    pref[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> v[i];
        pref[i] = pref[i-1] + v[i];
    }

    vector<ll> dp(n+2, LONG_LONG_MAX);
    dp[n+1] = 0;

    for(int i=n; i>0; i--) {
        for(int j=i; j<=n; j++) {
            int l = checkLine(i, j);
            if(l > m) break;
            ll cost = (j==n) ? 0 : 1LL*(m-l)*(m-l);
            dp[i] = min(dp[i], cost+dp[j+1]);
        }
    }

    cout << dp[1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}