#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 24447 (알고리즘 수업 - 너비 우선 탐색 4)
    solved by : minwoo0629a
*/

int n, m, r, in_idx;
bool v[100001];
vector<int> g[100001];
vector<int> t, d;

void bfs() {
    queue<int> q;
    v[r] = true;
    q.emplace(r);
    t[r] = ++in_idx; d[r] = 0;

    while(!q.empty()) {
        int c = q.front();
        q.pop();

        int size = g[c].size();
        f(i, size) {
            int nxt = g[c][i];
            if(v[nxt]) continue;

            q.emplace(nxt);
            v[nxt] = true;
            t[nxt] = ++in_idx;
            d[nxt] = d[c] + 1;
        }
    }
}

void solve() {
    cin >> n >> m >> r;
    t.resize(n+1); d.resize(n+1);

    f(i,m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        t[i] = 0; d[i] = -1;
        sort(g[i].begin(), g[i].end());
    }

    bfs();

    ll re = 0;
    for(int i=1; i<=n; i++) re += 1LL*t[i]*d[i];
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}