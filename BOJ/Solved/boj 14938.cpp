#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 14938 (서강그라운드)
    solved by : minwoo0629a
*/

int n, m, r, re;
int area[101], dist[101];
vector<pair<int, int>> g[101];
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void find(int start) {
    f(i,n) dist[i+1] = INT_MAX;
    dist[start] = 0;

    pq.emplace(start, 0);
    while(!pq.empty()) {
        int cur = pq.top().first;
        int len = pq.top().second;
        pq.pop();

        if(len > dist[cur]) continue;
        int size = g[cur].size();
        f(i, size) {
            int next = g[cur][i].first;
            int cost = g[cur][i].second;

            if(len+cost > dist[next]) continue;
            
            dist[next] = len + cost;
            pq.emplace(next, len+cost);
        }
    }

    int tmp=0;
    f(i, n) if(dist[i+1] <= m) tmp+=area[i+1];
    re = max(re, tmp);
}

void solve() {
    cin >> n >> m >> r;
    
    f(i, n) cin >> area[i+1];
    f(i, r) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    f(i, n) find(i+1);

    cout << re;    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}