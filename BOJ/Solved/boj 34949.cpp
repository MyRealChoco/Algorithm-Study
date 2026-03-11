#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 34949 (이대로 가면 되나요?)
    solved by : minwoo0629a
*/

int n;
vector<int> dist;
vector<vector<int>> g;

void dijk() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[n] = 0;
    pq.emplace(0, n);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();
    
        if(cost > dist[cur]) continue;

        for(auto nxt : g[cur]) {
            if(cost + 1 < dist[nxt]) {
                dist[nxt] = cost + 1;
                pq.emplace(cost+1, nxt);
            }
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n+1); dist.resize(n+1, INT_MAX);

    int tmp;
    f(i, n) {
        cin >> tmp;
        g[tmp].emplace_back(i+1);
    }

    dijk();
    for(int i=1; i<=n; i++) cout << (dist[i] == INT_MAX ? -1 : dist[i]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}