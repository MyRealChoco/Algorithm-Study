#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 10282 (해킹)
    solved by : minwoo0629a
*/

int t, n, d, c;
vector<ll> dist;
vector<vector<pair<int, int>>> g;

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, c);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(dist[cur] < cost) continue;

        for(auto n : g[cur]) {
            int nxt = n.first, nc = n.second;
            if(cost + nc < dist[nxt]) {
                dist[nxt] = cost + nc;
                pq.emplace(cost+nc, nxt);
            }
        }
    }

    int cnt=0;
    ll re=0;
    for(int i=1; i<=n; i++) {
        if(dist[i] != LONG_LONG_MAX) {
            cnt++;
            re = max(re, dist[i]);
        }
    }
    cout << cnt << " " << re << '\n';
}

void solve() {
    int a, b, s;
    cin >> t;
    while(t--) {
        dist.clear(); g.clear();
        cin >> n >> d >> c;
        dist.resize(n+1, LONG_LONG_MAX);
        g.resize(n+1);
        dist[c] = 0;

        f(i, d) {
            cin >> a >> b >> s;
            g[b].emplace_back(a, s);
        }

        dijk();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}