#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 12834 (주간 미팅)
    solved by : minwoo0629a
*/

int n, v, e, ta, tb, re;
vector<int> mem;
vector<vector<pair<int, int>>> g;

void dijk(int s) {
    vector<int> dist(v+1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto &[nxt, nc] : g[cur]) {
            if(cost + nc < dist[nxt]) {
                dist[nxt] = cost + nc;
                pq.emplace(cost+nc, nxt);
            }
        }
    }

    re += (dist[ta] == INT_MAX ? -1 : dist[ta]);
    re += (dist[tb] == INT_MAX ? -1 : dist[tb]);
}

void solve() {
    cin >> n >> v >> e;
    mem.resize(n); g.resize(v+1);
    
    cin >> ta >> tb;
    f(i, n) cin >> mem[i];

    int a, b, l;
    f(i, e) {
        cin >> a >> b >> l;
        g[a].emplace_back(b, l);
        g[b].emplace_back(a, l);
    }

    f(i, n) dijk(mem[i]);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}