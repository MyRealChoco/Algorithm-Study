#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 6593 (상범 빌딩)
    solved by : minwoo0629a
*/

int l, r, c, re;
char m[30][30][30];
bool v[30][30][30];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
tuple<int, int, int> s;

void bfs() {
    queue<tuple<int, int, int, int>> q;
    q.emplace(get<0>(s), get<1>(s), get<2>(s), 0);
    v[get<0>(s)][get<1>(s)][get<2>(s)] = true;

    while(!q.empty()) {
        auto[cz, cy, cx, cv] = q.front();
        q.pop();

        f(i, 6) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];
            int zt = cz + dz[i];

            if(xt<0 || yt<0 || zt<0 || xt>=c || yt>=r || zt>=l) continue;
            if(v[zt][yt][xt] || m[zt][yt][xt] == '#') continue;

            if(m[zt][yt][xt] == 'E') {
                re = cv+1;
                return;
            }
            
            v[zt][yt][xt] = true;
            q.emplace(zt, yt, xt, cv+1);
        }
    }
}

void solve() {
    while(true) {
        re = -1;
        memset(v, 0, sizeof(v));

        cin >> l >> r >> c;
        if(!l && !r && !c) break;

        f(i, l) f(j, r) f(k, c) {
            cin >> m[i][j][k];
            if(m[i][j][k] == 'S') s = {i, j, k};
        }
        bfs();
        if(re != -1) cout << "Escaped in " << re << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}