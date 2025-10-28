#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 17182 (우주 탐사선)
    solved by : minwoo0629a
*/

int n, k;
vector<pair<int, int>> g[10];
vector<int> dist[10];

void dijk(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[dis, cur] = pq.top();
        pq.pop();

        if(dis > dist[s][cur]) continue;

        int size = g[cur].size();
        f(i, size) {
            auto[cost, nxt] = g[cur][i];
            int n_dist = dis + cost;

            if(dist[s][nxt] > n_dist) {
                dist[s][nxt] = n_dist;
                pq.emplace(n_dist, nxt);
            }
        }
    }
}

ll checkMin() {
    ll re = LONG_LONG_MAX;
    int full = (1<<n);
    vector<vector<ll>> dp(full, vector<ll>(n, LONG_LONG_MAX));

    dp[1<<k][k] = 0;
    f(mask, full) {
        f(u, n) {
            ll cur = dp[mask][u];
            if(cur == LONG_LONG_MAX) continue;

            f(v, n) {
                if(mask & (1 << v)) continue;
                if(dist[u][v] == INT_MAX) continue;
                int nmask = mask | (1<<v);
                ll cost = cur + dist[u][v];

                if(cost < dp[nmask][v]) dp[nmask][v] = cost;
            }
        }
    }

    full--;
    f(u, n) re = min(re, dp[full][u]);
    return re;
}

void solve() {
    int tmp;
    cin >> n >> k;
    f(i, n) {
        dist[i].resize(n);
        f(j, n) dist[i][j] = (i==j ? 0 : INT_MAX);
    }

    f(i, n) {
        f(j, n) {
            cin >> tmp;
            if(i==j) continue;
            g[i].emplace_back(tmp, j);
        }
    }

    f(i, n) dijk(i);
    cout << checkMin();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}