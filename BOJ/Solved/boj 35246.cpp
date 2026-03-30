#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35426 (두쫀쿠 무료 나눔)
    solved by : minwoo0629a
*/

int n, m;
vector<ll> dist;
vector<vector<pair<int, ll>>> g;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

void solve() {
    cin >> n >> m;
    g.resize(n+2);
    dist.resize(n+2, LLONG_MAX);

    int p, q, r;
    ll cost;
    f(i, m) {
        cin >> p >> q >> r;
        if(r%2 == 0) continue;
        
        cost = 1LL * r * (q-p+1);
        g[p].emplace_back(q+1, cost);
        g[q+1].emplace_back(p, cost);
    }

    dist[1] = 0;
    pq.emplace(0, 1);

    while(!pq.empty()) {
        auto [c, cur] = pq.top();
        pq.pop();

        if(dist[cur] < c) continue;

        for(auto &[nxt, cost] : g[cur]) {
            if(dist[nxt] > c + cost) {
                dist[nxt] = c + cost;
                pq.emplace(dist[nxt], nxt);
            }
        }
    }

    if(dist[n+1] == LLONG_MAX) cout << "Dujjonku so expensive T.T";
    else cout << dist[n+1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}