#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1719 (택배)
    solved by : minwoo0629a
*/

int n, m;
int dist[201], hop[201];
int re[201][201];
vector<pair<int, int>> g[201];
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void find(int start) {
    f(i,n) {dist[i+1] = INT_MAX; hop[i] = 0;}
    dist[start] = 0;

    pq.emplace(0, start);
    while(!pq.empty()) {
        int len = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < len) continue;
        int size = g[cur].size();
        f(i, size) {
            int next = g[cur][i].first;
            int cost = g[cur][i].second;

            if(dist[next] <= len+cost) continue;
            
            hop[next] = (cur == start ? next : hop[cur]);
            dist[next] = len + cost;
            pq.emplace(len+cost, next);
        }
    }

    for (int t = 1; t <= n; ++t) {
        if (t == start) re[start][t] = 0;
        else re[start][t] = hop[t];
    }
}

void solve() {
    cin >> n >> m;
    f(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    f(i, n) find(i+1);

    f(i, n) {
        f(j, n) {
            if(i==j) cout << "- ";
            else cout << re[i+1][j+1] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}