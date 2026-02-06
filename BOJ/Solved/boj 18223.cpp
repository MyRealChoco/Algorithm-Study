#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 18223 (민준이와 마산 그리고 건우)
    solved by : minwoo0629a
*/

int v, e, p, re, tmp;
vector<int> dist;
vector<vector<pair<int, int>>> g;

void dijk(int s) {
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto x : g[cur]) {
            if(cost + x.second < dist[x.first]) {
                dist[x.first] = cost + x.second;
                pq.emplace(cost + x.second, x.first);
            }
        }
    }
}

void solve() {
    cin >> v >> e >> p;
    g.resize(v+1); dist.resize(v+1);
    f(i, v+1) dist[i] = INT_MAX;
    dist[1] = 0;
    
    int a, b, c;
    f(i, e) {
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    dijk(1);
    re = dist[v];
    tmp = dist[p];
    
    f(i, v+1) dist[i] = INT_MAX;
    dist[p] = 0;
    dijk(p);
    tmp += dist[v];

    cout << (re==tmp ? "SAVE HIM" : "GOOD BYE");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}