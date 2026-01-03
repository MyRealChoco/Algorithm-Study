#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 4781 (사탕 가게)
    solved by : minwoo0629a
*/

int n, m;
vector<int> dp(10001, 0);

void solve() {
    while(true) {
        int c, p; double tmp;
        cin >> n >> tmp;
        m = round(tmp*100);
        fill(dp.begin(), dp.begin() + m + 1, 0);

        if(n == 0 && m == 0) return;

        f(i, n) {
            cin >> c >> tmp;
            p = round(tmp*100);
            
            for(int j=p; j<=m; j++) {
                dp[j] = max(dp[j], dp[j-p] + c);
            }
        }

        cout << dp[m] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}