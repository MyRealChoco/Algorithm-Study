#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 15483 (최소 편집)
    solved by : minwoo0629a
*/

string a, b;
int dp[1001][1001];

void solve() {
    cin >> a >> b;
    int asize = a.length();
    int bsize = b.length();

    f(i, bsize+1) dp[0][i] = i;
    f(i, asize+1) dp[i][0] = i;

    for(int i=1; i<=bsize; i++) {
        for(int j=1; j<=asize; j++) {
            if(a[j-1] == b[i-1]) dp[j][i] = dp[j-1][i-1];
            else dp[j][i] = min({dp[j-1][i], dp[j][i-1], dp[j-1][i-1]}) + 1;
        }
    }

    cout << dp[asize][bsize];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}