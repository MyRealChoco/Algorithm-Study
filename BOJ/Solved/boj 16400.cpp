#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16400 (소수 화폐)
    solved by : minwoo0629a
*/

int n;
bool p[40001];
vector<int> v, dp;

void solve() {
    p[1] = true;
    for(int i=2; i<200; i++) {
        if(!p[i]) for(int j=i+i; j<=40000; j+=i) p[j] = true;
    }

    cin >> n;
    dp.resize(n+1, 0);
    for(int i=2; i<=n; i++) if(!p[i]) v.emplace_back(i);

    dp[0] = 1;
    for(int p : v) {
        for(int j=p; j<=n; j++) {
            dp[j] += dp[j-p];
            dp[j] %= 123456789;
        }
    }
    cout << dp[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}