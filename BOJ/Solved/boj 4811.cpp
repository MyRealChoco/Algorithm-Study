#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 4811 (알약)
    solved by : minwoo0629a
*/

int n;
vector<ll> dp(31, 0);

void solve() {
    dp[0] = 1;
    
    for(int i=1; i<=30; i++) {
        for(int j=0; j<i; j++) dp[i] += dp[j] * dp[i-1-j];
    }

    while(true) {
        cin >> n;
        if(!n) break;
        cout << dp[n] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}