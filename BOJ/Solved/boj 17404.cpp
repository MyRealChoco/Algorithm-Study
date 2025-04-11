#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
problem : boj 17404 (RGB거리 2)
solved by : minwoo0629a
*/

int n, re = 1000001;
int dp[1000][3];
int c[1000][3];

void solve() {
    cin >> n;
    f(i,n) cin >> c[i][0] >> c[i][1] >> c[i][2];

    // r g b 선택
    f(i, 3) {
        f(j, 3) {
            if(i == j) dp[0][j] = c[0][j];
            else dp[0][j] = 1000001;
        }

        for(int j=1; j<n; j++) {
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + c[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + c[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + c[j][2];
        }

        f(j, 3) {
            if(j == i) continue;
            re = min(re, dp[n-1][j]);
        }
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}