#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 23324 (어려운 모든 정점 쌍 최단 거리)
    solved by : minwoo0629a
*/

int n, m, k;
ll cnt;
bool visited[100001];
vector<vector<int>> g;

void bfs(int s) {
    queue<int> q;
    q.emplace(s);
    visited[s] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for(auto x : g[cur]) {
            if(visited[x]) continue;
            visited[x] = true;
            q.emplace(x);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    g.resize(n+1);

    int a, b;
    f(i, m) {
        cin >> a >> b;

        if(i == k-1) continue;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    bfs(1);
    cout << cnt * (n-cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}