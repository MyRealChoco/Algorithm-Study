#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 23034 (조별과제 멈춰!)
    solved by : minwoo0629a
*/

int n, m, p[1001], mx, tot;
bool visited[1001];
vector<tuple<int, int, int>> v;
vector<vector<pair<int, int>>> g;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}
void dfs(int cur, int goal, int m) {
    if(cur == goal) {
        mx = max(mx, m);
        return;
    }

    for(auto &[nxt, cost] : g[cur]) {
        if(visited[nxt]) continue;

        visited[nxt] = true;
        dfs(nxt, goal, max(m, cost));
        visited[nxt] = false;
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);
    f(i, n+1) p[i] = i;
    
    int a, b, c;
    f(i, m) {
        cin >> a >> b >> c;
        v.emplace_back(c, a, b);
    }
    
    sort(v.begin(), v.end());
    for(auto &[cost, a, b] : v) {
        if(findP(a) != findP(b)) {
            tot += cost;
            p[findP(a)] = findP(b);
            g[a].emplace_back(b, cost);
            g[b].emplace_back(a, cost);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        memset(visited, 0, sizeof(visited));
        mx = 0;
        cin >> a >> b;

        visited[a] = true;
        dfs(a, b, 0);
        cout << tot - mx << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}