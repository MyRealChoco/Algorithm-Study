#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 13424 (비밀 모임)
    solved by : minwoo0629a
*/

int t, n, m, k;
vector<int> v, dist;
vector<vector<pair<int, int>>> g;

void dijk(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[cur]) continue;

        for(auto &[nxt, c] : g[cur]) {
            if(cost + c < dist[nxt]) {
                dist[nxt] = cost + c;
                pq.emplace(cost+c, nxt);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(v[i] == -1) v[i] = dist[i];
        else v[i] += dist[i];
    }
}

void solve() {
    int a, b, c;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        v.clear(); dist.clear(); g.clear();
        v.resize(n+1, -1); dist.resize(n+1, INT_MAX); g.resize(n+1);

        f(i, m) {
            cin >> a >> b >> c;
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }

        cin >> k;
        f(i, k) {
            cin >> a;
            fill(dist.begin(), dist.end(), INT_MAX);
            dijk(a);
        }
        int mn=INT_MAX, re;
        for(int i=1; i<=n; i++) {
            if(v[i] == -1) continue;
            if(v[i] < mn) {
                mn = v[i];
                re = i;
            }
        }
        cout << re << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}