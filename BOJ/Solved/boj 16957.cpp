#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16957 (체스판 위의 공)
    solved by : minwoo0629a
*/

int r, c;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
vector<vector<int>> v, dp, re;
queue<pair<int, int>> q;

int h(int x, int y) {
    return x*1000 + y;
}
pair<int,int> rh(int a) {
    return make_pair(a/1000, a%1000);
}

void bfs(int x, int y) {
    int l, rx, ry;
    while(!q.empty()) q.pop();
    q.emplace(x, y);

    while(!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        l = INT_MAX;
        f(i, 8) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>=c || yt>=r) continue;
            
            if(v[yt][xt] < v[cy][cx] && v[yt][xt] < l) {
                l = v[yt][xt];
                rx = xt; ry = yt;
            }
        }

        if(l == INT_MAX) {
            dp[y][x] = h(cx, cy);
            re[cy][cx]++;
        } else {
            if(dp[ry][rx] != -1) {
                dp[y][x] = dp[ry][rx];
                auto [nx, ny] = rh(dp[ry][rx]);
                re[ny][nx]++;
                break;
            }
            else q.emplace(rx, ry);
        }
    }
}

void solve() {
    cin >> r >> c;
    v.resize(r, vector<int>(c)); dp.resize(r, vector<int>(c, -1)); re.resize(r, vector<int>(c, 0));
    f(i, r) f(j, c) cin >> v[i][j];

    f(i, r) f(j, c) bfs(j, i);

    f(i, r) {f(j, c) cout << re[i][j] << " "; cout << '\n';}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}