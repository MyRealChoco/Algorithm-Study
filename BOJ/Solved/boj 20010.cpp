#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 20010 (악덕 영주 혜유)
    solved by : minwoo0629a
*/

int n, k, re;
vector<int> p;
bool visited[1000];
vector<tuple<int, int, int>> v;
vector<vector<pair<int, int>>> g;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void dfs(int s, int cost) {
    re = max(re, cost);

    for(auto n : g[s]) {
        int nxt = n.first;
        int nc = cost + n.second;

        if(!visited[nxt]) {
            visited[nxt] = true;
            dfs(nxt, nc);
            visited[nxt] = false;
        }
    }
}

void solve() {
    cin >> n >> k;
    p.resize(n); g.resize(n);
    f(i, n) p[i] = i;

    int a, b, c;
    f(i, k) {
        cin >> a >> b >> c;
        v.emplace_back(c, a, b);
    }

    sort(v.begin(), v.end());
    f(i, k) {
        auto[c, a, b] = v[i];

        if(findP(a) != findP(b)) {
            re += c;
            p[findP(a)] = findP(b);
            g[a].emplace_back(b, c);
            g[b].emplace_back(a, c);
        }
    }
    cout << re << '\n';

    re = 0;
    f(i, n) {
        memset(visited, 0, sizeof(visited));
        visited[i] = true;
        dfs(i, 0);
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}