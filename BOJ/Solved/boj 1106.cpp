#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
#define inf 1234567890
using namespace std;

/*
problem : boj 1106 (호텔)
solved by : minwoo0629a
*/

vector<pair<int, int>> v;
int dp[1101];

void solve() {
    int c, n;
    cin >> c >> n;

    f(i, n) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    fill(dp, dp + 1101, inf);
    dp[0] = 0;

    for(auto &x : v){
        for(int i= x.second; i<1101; i++) {
            dp[i] = min(dp[i], dp[i-x.second] + x.first);
        }
    }
    
    cout << *min_element(dp+c, dp+1101);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}