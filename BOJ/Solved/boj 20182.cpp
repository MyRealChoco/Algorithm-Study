#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 20182 (골목 대장 호석 - 효율성 1)
    solved by : minwoo0629a
*/

int n, m, a, b, c;
int dist[100001];
vector<vector<pair<int, int>>> g;

bool dijk(int mx) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    f(i, n+1) dist[i] = INT_MAX;
    pq.emplace(0, a);
    dist[a]=0;

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;
        if(cost > c) continue;
        if(cur == b) {
            cout << mx;
            return true;
        }

        for(auto &[nxt, nc] : g[cur]) {
            if(nc > mx) continue;
            if(cost+nc >= dist[nxt]) continue;
            
            dist[nxt] = cost + nc;
            pq.emplace(cost+nc, nxt);
        }
    }

    return false;
}

void solve() {
    cin >> n >> m >> a >> b >> c;
    g.resize(n+1);

    int x, y, z;
    f(i, m) {
        cin >> x >> y >> z;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }

    f(i, 20) if(dijk(i+1)) return;
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}