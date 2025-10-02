#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1240 (노드사이의 거리)
    solved by : minwoo0629a
*/

int n, m;
int g[1001][1001];
bool visited[1001];

int bfs(int a, int b) {
    memset(visited, 0, sizeof(bool)*1001);
    queue<pair<int, int>> q;
    visited[a] = true;
    q.push({a, 0});

    while(!q.empty()) {
        int cur= q.front().first;
        int cost = q.front().second;
        q.pop();

        for(int i=1; i<=n; i++) {
            if(!g[cur][i] || visited[i]) continue;
            
            visited[i] = true;
            if(i == b) return cost + g[cur][i];
            else q.push({i, cost+g[cur][i]});
        }
    }
    return -1;
}

void solve() {
    int a, b, c;
    cin >> n >> m;
    
    f(i, n-1) {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }

    while(m--) {
        cin >> a >> b;
        if(g[a][b]) cout << g[a][b] << "\n";
        else cout << bfs(a, b) << "\n";       
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}