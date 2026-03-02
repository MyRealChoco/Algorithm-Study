#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14671 (영정이의 청소)
    solved by : minwoo0629a
*/

bool re;
int n, m, k;
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
vector<vector<bool>> v[2], visited[2];
queue<tuple<int, int, int>> q;

void solve() {
    cin >> m >> n >> k;
    f(i, 2) {
        v[i].resize(n, vector<bool>(m, false));
        visited[i].resize(n, vector<bool>(m, false));
    }

    int x, y;
    f(i, k) {
        cin >> y >> x;
        x--; y--;
        v[0][y][x] = true;
        visited[0][y][x] = true;
        q.emplace(x, y, 0);
    }

    while(!q.empty()) {
        auto[x, y, p] = q.front();
        q.pop();

        int cp = p ^ 1;

        f(i, 4) {
            int xt = x + dx[i];
            int yt = y + dy[i];

            if(xt<0 || yt<0 || xt>=m || yt>=n) continue;
            if(visited[cp][yt][xt]) continue;

            visited[cp][yt][xt] = true;
            q.emplace(xt, yt, cp);
        }
    }

    f(i, 2) {
        bool f = true;
        f(j, n) f(k, m) if(!visited[i][j][k]) f=false;
        if(f) re = true;
    }

    cout << (re ? "YES" : "NO");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}