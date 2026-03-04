#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 6156 (Cow Contest)
    solved by : minwoo0629a
*/

int n, m, re;
vector<vector<int>> v_w, v_l;
bool visited[101];

void bfs(int v) {
    queue<int> q;
    memset(visited, false, sizeof(visited));

    q.emplace(v);
    visited[v] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto nxt : v_w[cur]) {
            if(visited[nxt]) continue;
            
            visited[nxt] = true;
            q.emplace(nxt);
        }
    }
    
    q.emplace(v);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(auto nxt : v_l[cur]) {
            if(visited[nxt]) continue;

            visited[nxt] = true;
            q.emplace(nxt);
        }
    }

    bool f = true;
    for(int i=1; i<=n; i++) if(!visited[i]) f = false;
    if(f) re++;
}

void solve() {
    cin >> n >> m;
    v_w.resize(n+1); v_l.resize(n+1);

    int a, b;
    f(i, m) {
        cin >> a >> b;
        v_w[a].emplace_back(b);
        v_l[b].emplace_back(a);
    }

    for(int i=1; i<=n; i++) bfs(i);

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}