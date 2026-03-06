#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16174 (점프왕 쩰리 (Large))
    solved by : minwoo0629a
*/

int n;
bool re;
vector<vector<int>> v;
bool visited[64][64];

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = true;

    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();

        if(x==n-1 && y==n-1) {
            re = true;
            return;
        }
        if(v[y][x] == 0) continue;

        f(i, 2) {
            int xt = x + (i == 0 ? v[y][x] : 0);
            int yt = y + (i == 0 ? 0 : v[y][x]);

            if(xt<0 || yt<0 || xt>=n || yt>=n) continue;
            if(visited[yt][xt]) continue;

            visited[yt][xt] = true;
            q.emplace(xt, yt);
        }
    }
}

void solve() {
    cin >> n;
    v.resize(n, vector<int>(n));

    f(i, n) f(j, n) cin >> v[i][j];

    bfs();
    cout << (re ? "HaruHaru" : "Hing");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}