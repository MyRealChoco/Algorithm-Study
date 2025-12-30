#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5549 (행성 탐사)
    solved by : minwoo0629a
*/

int m, n, k;

void solve() {
    string s;
    cin >> m >> n >> k;
    vector<vector<int>> ju(m+1, vector<int>(n+1, 0)), o(m+1, vector<int>(n+1, 0)), ic(m+1, vector<int>(n+1, 0));
    
    for(int i=1; i<=m; i++) {
        cin >> s;

        for(int j=1; j<=n; j++) {
            ju[i][j] = ju[i-1][j] + ju[i][j-1] - ju[i-1][j-1] + (s[j-1] == 'J' ? 1 : 0);
            o[i][j] = o[i-1][j] + o[i][j-1] - o[i-1][j-1] + (s[j-1] == 'O' ? 1 : 0);
            ic[i][j] = ic[i-1][j] + ic[i][j-1] - ic[i-1][j-1] + (s[j-1] == 'I' ? 1 : 0);
        }
    }

    while(k--) {
        int a, b, c, d, j_c, o_c, i_c;

        cin >> a >> b >> c >> d;
        
        j_c = ju[c][d] - ju[a-1][d] - ju[c][b-1] + ju[a-1][b-1];
        o_c = o[c][d] - o[a-1][d] - o[c][b-1] + o[a-1][b-1];
        i_c = ic[c][d] - ic[a-1][d] - ic[c][b-1] + ic[a-1][b-1];

        cout << j_c << " " <<  o_c <<  " " << i_c << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}