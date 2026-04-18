#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16509 (장군)
    solved by : minwoo0629a
*/

int r1, c1, r2, c2, re;
int dx[8] = {2, 3, 3, 2, -2, -3, -3, -2};
int dy[8] = {-3, -2, 2, 3, 3, 2, -2, -3};

int mdx1[8] = {0, 1, 1, 0, 0, -1, -1, 0};
int mdy1[8] = {-1, 0, 0, 1, 1, 0, 0, -1};

int mdx2[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int mdy2[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool visited[10][9];

void bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(r1, c1, 0);
    visited[r1][c1] = true;

    while(!q.empty()) {
        auto [r, c, cost] = q.front();
        q.pop();

        if(r==r2 && c==c2) {
            cout << cost;
            return;
        }

        f(i, 8) {
            int nc = c + dx[i];
            int nr = r + dy[i];

            if(nr<0 || nc<0 || nr>9 || nc>8) continue;
            if(r + mdy1[i] == r2 && c + mdx1[i] == c2) continue;
            if(r + mdy2[i] == r2 && c + mdx2[i] == c2) continue;

            if(visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.emplace(nr, nc, cost+1);
        }
    }

    cout << -1;
}

void solve() {
    cin >> r1 >> c1 >> r2 >> c2;
    bfs();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}