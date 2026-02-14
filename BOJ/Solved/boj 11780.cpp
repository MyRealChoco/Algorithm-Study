#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 11780 (플로이드 2)
    solved by : minwoo0629a
*/

int n, m;
int g[101][101], dist[101][101], parent[101][101];

void dijk(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[cost, cur] = pq.top();
        pq.pop();

        if(cost > dist[s][cur]) continue;

        for(int i=1; i<=n; i++) {
            if(g[cur][i] == INT_MAX || !g[cur][i]) continue;
            
            int nc = cost + g[cur][i];
            if(nc < dist[s][i]) {
                parent[s][i] = cur;
                dist[s][i] = nc;
                pq.emplace(nc, i);
            }
        }
    }
}

void solve() {
    int a, b, c;
    cin >> n >> m;

    f(i, n+1) f(j, n+1) g[i][j] = dist[i][j] = (i==j ? 0 : INT_MAX);

    f(i, m) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    for(int i=1; i<=n; i++) dijk(i);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cout << (dist[i][j] == INT_MAX ? 0 : dist[i][j]) << " ";
        cout << '\n';
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j || dist[i][j] == INT_MAX) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> path;
            int cur = j;
            while(cur != i) {
                path.emplace_back(cur);
                cur = parent[i][cur];
                if(cur == 0) break;
            }
            path.emplace_back(i);
            reverse(path.begin(), path.end());

            cout << path.size()  << " ";
            for(int v : path) cout << v << " ";
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}