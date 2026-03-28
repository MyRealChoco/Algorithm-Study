#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 2660 (회장뽑기)
    solved by : minwoo0629a
*/

int n, re=INT_MAX, cnt;
bool visited[51];
vector<int> v;
vector<vector<int>> g;

void bfs(int s) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    visited[s] = true;

    int mx = 0;
    while(!q.empty()) {
        auto &[cur, cost] = q.front();
        q.pop();

        mx = max(mx, cost);

        for(auto &nxt : g[cur]) {
            if(!visited[nxt]) {
                visited[nxt] = true;
                q.emplace(nxt, cost+1);
            }
        }
    }

    f(i, n) if(!visited[i+1]) return;

    v[s] = mx;
    if(mx < re) {re = mx; cnt=1;}
    else if(mx == re) cnt++;
}

void solve() {
    cin >> n;
    v.resize(n+1, INT_MAX); g.resize(n+1);
    int a, b;
    while(true) {
        cin >> a >> b;
        if(a==-1 && b==-1) break;

        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    f(i, n) bfs(i+1);

    cout << re << " " << cnt << '\n';
    f(i, n) if(v[i+1] == re) cout << i+1 << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}