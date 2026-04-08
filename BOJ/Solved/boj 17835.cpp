#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17835 (면접보는 승범이네)
    solved by : minwoo0629a
*/

int n, m, k;
ll dist[100001];
vector<int> b;
vector<vector<pair<int, int>>> g;

void dijk() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    f(i, n+1) dist[i] = LLONG_MAX;
    for(auto &a : b) {
        dist[a] = 0;
        pq.emplace(0, a);
    }

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto &[nxt, nc] : g[cur]) {
            if(cost+nc < dist[nxt]) {
                dist[nxt] = cost+nc;
                pq.emplace(cost+nc, nxt);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    g.resize(n+1);

    int u, v, c;
    f(i, m) {
        cin >> u >> v >> c;
        g[v].emplace_back(u, c);
    }
    f(i, k) {
        cin >> c;
        b.emplace_back(c);
    }

    dijk();

    ll max=-1, re;
    for(int i=1; i<=n; i++) {
        if(dist[i] > max) {
            max = dist[i];
            re = i;
        }
    }

    cout << re << '\n' << max;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}