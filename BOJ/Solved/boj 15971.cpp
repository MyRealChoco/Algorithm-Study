#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 15971 (두 로봇)
    solved by : minwoo0629a
*/

int n, a, b;
int dist[100001], mx[100001];
vector<vector<pair<int, int>>> g;

void dijk(int s) {
    vector<bool> visited(n+1, false);
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    visited[s] = true;
    dist[s] = 0;
    pq.emplace(0, s, 0);

    while(!pq.empty()) {
        auto [cost, cur, cmx] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto &[nxt, nc] : g[cur]) {
            if(cost + nc < dist[nxt]) {
                dist[nxt] = cost + nc;
                mx[nxt] = max(cmx, nc);
                pq.emplace(cost+nc, nxt, max(cmx, nc));
            }
        }
    }
}

void solve() {
    cin >> n >> a >> b;
    g.resize(n+1);
    f(i, n+1) dist[i] = INT_MAX;

    int x, y, z;
    f(i, n-1) {
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }

    dijk(a);
    cout << dist[b] - mx[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}