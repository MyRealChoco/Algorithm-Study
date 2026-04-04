#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14450 (Hoof, Paper, Scissors (Gold))
    solved by : minwoo0629a
*/

int n, k;
int dp[100001][21][3];
vector<int> v;

int win(int a, int b) {
    if(a == 0 && b == 2) return 1;
    if(a == 1 && b == 0) return 1;
    if(a == 2 && b == 1) return 1;
    return 0;
}

void solve() {
    cin >> n >> k;
    v.resize(n+1);

    char c;
    for(int i=1; i<=n; i++) {
        cin >> c;
        if(c == 'H') v[i] = 0;
        else if(c == 'P') v[i] = 1;
        else v[i] = 2;
    }

    memset(dp, -1, sizeof(dp));
    f(i, 3) dp[1][0][i] = win(i, v[1]);

    for(int i=2; i<=n; i++) {
        f(j, k+1) {
            f(g, 3) {
                if(dp[i-1][j][g] != -1) dp[i][j][g] = max(dp[i][j][g], dp[i-1][j][g] + win(g, v[i]));

                if(j > 0) {
                    f(pg, 3) {
                        if(pg == g) continue;
                        if(dp[i-1][j-1][pg] != -1) dp[i][j][g] = max(dp[i][j][g], dp[i-1][j-1][pg] + win(g, v[i]));
                    }
                }
            }
        }
    }

    int re = 0;
    f(j, k+1) f(g, 3) re = max(re, dp[n][j][g]);

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}