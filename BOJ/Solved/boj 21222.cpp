#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 21222 (Alias)
    solved by : minwoo0629a
*/

int n, m, q, idx;
vector<bool> v;
vector<vector<ll>> dist;
vector<pair<int, int>> query;
vector<vector<pair<int, ll>>> g;

unordered_map<string, int> mp;

void dijk(int s) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s][s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[s][cur]) continue;

        for(auto &[nxt, nc] : g[cur]) {
            if(cost + nc < dist[s][nxt]) {
                dist[s][nxt] = cost + nc;
                pq.emplace(dist[s][nxt], nxt);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n+1); v.resize(n+1, false);
    dist.resize(n+1, vector<ll>(n+1, LLONG_MAX));

    string a, b;
    ll t;
    f(i, m) {
        cin >> a >> b >> t;

        if(!mp.count(a)) mp[a] = ++idx;
        if(!mp.count(b)) mp[b] = ++idx;

        g[mp[a]].emplace_back(mp[b], t);
    }

    cin >> q;
    f(i, q) {
        cin >> a >> b;
        query.emplace_back(mp[a], mp[b]);
    }
    for(auto &[s, e] : query) {
        if(!v[s]) {
            dijk(s);
            v[s] = true;
        }

        if(dist[s][e] == LLONG_MAX) cout << "Roger\n";
        else cout << dist[s][e] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
