#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17142 (연구소 3)
    solved by : minwoo0629a
*/

int n, m, vs, re=INT_MAX, visited[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> v;
vector<pair<int, int>> virus, st;

int bfs() {
    int re = 0;
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, int>> q;

    for(auto &[x, y] : st) {
        visited[y][x] = true;
        q.emplace(0, x, y);
    }

    while(!q.empty()) {
        auto[cur, x, y] = q.front();
        q.pop();

        f(i, 4) {
            int xt = x + dx[i];
            int yt = y + dy[i];

            if(xt<0 || yt<0 || xt>=n || yt>=n) continue;
            if(visited[yt][xt] || v[yt][xt] == 1) continue;
       
            visited[yt][xt] = true;
            q.emplace(cur+1, xt, yt);
            if(v[yt][xt] != 2) re = max(re, cur+1);
        }
    }

    bool f = true;
    f(i, n) f(j, n) if(v[i][j] == 0 && !visited[i][j]) f = false;

    return (f ? re : -1);
}

void bt(int bef, int cnt) {
    if(cnt == m) {
        int tmp = bfs();
        if(tmp != -1) re = min(re, tmp);
        return;
    }

    for(int i=bef+1; i<vs; i++) {
        st.emplace_back(virus[i].first, virus[i].second);
        bt(i, cnt+1);
        st.pop_back();
    }
}

void solve() {
    cin >> n >> m;
    v.resize(n, vector<int>(n));

    f(i, n) f(j, n) {
        cin >> v[i][j];
        if(v[i][j] == 2) virus.emplace_back(j, i);
    }
    vs = virus.size();

    bt(-1, 0);
    cout << (re == INT_MAX ? -1 : re);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}