#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 11660 (구간 합 구하기 5)
    solved by : minwoo0629a
*/

int n, m;
vector<vector<int>> s;

void solve() {
    cin >> n >> m;
    s.resize(n+1, vector<int>(n+1));

    int tmp;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> tmp;
            s[i][j] = tmp + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    }

    f(i, m) {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << s[y2][x2] - s[y2][x1-1] - s[y1-1][x2] + s[y1-1][x1-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}