#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1189 (컴백홈)
    solved by : minwoo0629a
*/

int r, c, k, re;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string s[5];
bool visited[5][5];

void dfs(int x, int y, int len) {
    if(len >= k) {
        if(x == c-1 && y == 0) re++;
        return;
    }

    f(i, 4) {
        int xt = x + dx[i];
        int yt = y + dy[i];

        if(xt<0 || yt<0 || xt>=c || yt>=r) continue;
        if(visited[yt][xt] || s[yt][xt] == 'T') continue;
        
        visited[yt][xt] = true;
        dfs(xt, yt, len+1);
        visited[yt][xt] = false;
    }
}

void solve() {
    cin >> r >> c >> k;
    f(i, r) cin >> s[i];

    visited[r-1][0] = true;
    dfs(0, r-1, 1);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}