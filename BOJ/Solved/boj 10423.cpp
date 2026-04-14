#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 10423 (전기가 부족해)
    solved by : minwoo0629a
*/

int n, m, k, re;
bool used[1001];
vector<int> p;
vector<tuple<int, int, int>> g;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    int u, v, w;

    cin >> n >> m >> k;
    p.resize(n+1);
    f(i, n+1) p[i] = i;
    f(i, k) {
        cin >> u;
        used[u] = true;
    }
    f(i, m) {
        cin >> u >> v >> w;
        g.emplace_back(w, u, v);
    }
    sort(g.begin(), g.end());

    for(auto &[w, u, v] : g) {
        int pu = findP(u);
        int pv = findP(v);

        if(pu == pv) continue;
        if(used[pu] && used[pv]) continue;

        re += w;
        p[pu] = pv;
        used[pv] = used[pu] || used[pv];
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}