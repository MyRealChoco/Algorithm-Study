#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17218 (비밀번호 만들기)
    solved by : minwoo0629a
*/

string a, b;

void solve() {
    cin >> a >> b;

    int al = a.length(), bl = b.length();
    vector<vector<int>> dp(bl+1, vector<int>(al+1, 0));

    for(int i=1; i<=al; i++) {
        for(int j=1; j<=bl; j++) {
            if(a[i-1] == b[j-1]) dp[j][i] = dp[j-1][i-1] + 1;
            else dp[j][i] = max(dp[j-1][i], dp[j][i-1]);
        }
    }

    stack<char> s;
    int i=al, j=bl;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            s.emplace(a[i - 1]);
            i--; j--;
        } else {
            if (dp[j][i] > dp[j][i-1]) j--;
            else i--;
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}