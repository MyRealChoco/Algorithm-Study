#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1245 (농장 관리)
    solved by : minwoo0629a
*/

int n, m, re;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
vector<vector<int>> v;
vector<vector<bool>> visited;

void bfs(int x, int y, int c) {
    queue<tuple<int, int, int>> q;
    visited[y][x] = true;
    q.emplace(x, y, c);

    while(!q.empty()) {
        auto[cx, cy, cur] = q.front();
        q.pop();

        f(i, 8) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>=m || yt>=n) continue;
            if(visited[yt][xt] || v[yt][xt] > cur) continue;

            visited[yt][xt] = true;
            q.emplace(xt, yt, v[yt][xt]);
        }
    }
}

void solve() {
    cin >> n >> m;
    v.resize(n, vector<int>(m)); visited.resize(n, vector<bool>(m, 0));
    f(i, n) f(j, m) cin >> v[i][j];

    // worst case : 500 * 100 * 70 = 3500000
    for(int c=500; c>-1; c--) {
        f(i, n) f(j, m) if(!visited[i][j] && v[i][j] == c) {bfs(j, i, c); re++;}
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}