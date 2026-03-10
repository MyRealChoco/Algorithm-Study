#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17472 (다리 만들기 2)
    solved by : minwoo0629a
*/

int n, m, cnt;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> p;
vector<vector<int>> v;
vector<tuple<int, int, int>> g;
bool visited[10][10];

int find_p(int v) {
    if(p[v] == v) return v;
    else return p[v] = find_p(p[v]);
}
void bfs(int x, int y, int num) {
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while(!q.empty()) {
        auto[cx, cy] = q.front();
        q.pop();

        f(i, 4) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>=m || yt>=n) continue;
            if(visited[yt][xt] || !v[yt][xt]) continue;

            visited[yt][xt] = true;
            v[yt][xt] = num;
            q.emplace(xt, yt);
        }
    }
}
void mark() {
    f(i, n) f(j, m) {
        if(v[i][j] && !visited[i][j]) {
            cnt++;
            v[i][j] = cnt;
            visited[i][j] = true;
            bfs(j, i, cnt);
        }
    }
}
void find_path() {
    f(i, n) f(j, m) {
        if(v[i][j]) {
            f(k, 4) {
                int xt = j + dx[k];
                int yt = i + dy[k];

                while(xt>-1 && yt>-1 && xt<m && yt<n) {
                    if(v[yt][xt]) {
                        int dist = (xt-j) + (yt-i) - 1;
                        if(dist>=2) g.emplace_back(dist, v[i][j], v[yt][xt]);
                        break;
                    }

                    xt += dx[k];
                    yt += dy[k];
                }
            }
        }
    }
}
void mst() {
    int re = 0;
    sort(g.begin(), g.end());
    
    for(auto[cost, a, b] : g) {
        if(find_p(a) != find_p(b)) {
            p[find_p(a)] = find_p(b);
            re += cost;
        }
    }

    int t = find_p(1);
    for(int i=2; i<=cnt; i++) if(find_p(i) != t) {
        cout << -1;
        return;
    }

    cout << re;
}

void solve() {
    cin >> n >> m;
    v.resize(n, vector<int>(m));
    f(i, n) f(j, m) cin >> v[i][j];

    mark();
    g.resize(cnt+1); p.resize(cnt+1);
    f(i, cnt+1) p[i] = i;
    find_path();
    mst();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}