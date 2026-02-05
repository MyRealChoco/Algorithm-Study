#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 18170 (두 동전 언리미티드)
    solved by : minwoo0629a
*/

int n, m, re=-1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool used[20][20][20][20];
vector<string> v;

void bfs(int fx, int fy, int sx, int sy) {
    queue<tuple<int, int, int, int, int>> q;
    q.emplace(fx, fy, sx, sy, 0);
    used[fx][fy][sx][sy] = true;

    while(!q.empty()) {
        auto[fx, fy, sx, sy, cnt] = q.front();
        q.pop();

        f(i, 4) {
            int xt1 = fx + dx[i], xt2 = sx + dx[i];
            int yt1 = fy + dy[i], yt2 = sy + dy[i];

            bool f1, f2;
            f1 = f2 = true;

            if(xt1<0 || xt1>=m || yt1<0 || yt1>=n) f1 = false;
            if(xt2<0 || xt2>=m || yt2<0 || yt2>=n) f2 = false;

            if(f1 != f2) {
                re = cnt+1;
                return;
            } else {
                if(!f1) continue;
            }

            if(v[yt1][xt1] == '#') {
                xt1 = fx;
                yt1 = fy;
            }
            if(v[yt2][xt2] == '#') {
                xt2 = sx;
                yt2 = sy;
            }

            if(!used[xt1][yt1][xt2][yt2]) {
                used[xt1][yt1][xt2][yt2] = true;
                q.emplace(xt1, yt1, xt2, yt2, cnt+1);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    v.resize(n);

    f(i, n) cin >> v[i];

    int fx, fy, sx, sy;
    fx = fy = -1;
    f(i, n) {
        f(j, m) {
            if(v[i][j] == 'o') {
                if(fx == -1) {
                    fx = j;
                    fy = i;
                }
                else {
                    sx = j;
                    sy = i;
                }
            }
        }
    }

    bfs(fx, fy, sx, sy);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}