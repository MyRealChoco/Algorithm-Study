#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 10159 (저울)
    solved by : minwoo0629a
*/

int n, m;
bool visited[101];
vector<vector<int>> l, r;

void dfs_l(int a) {
    int s = l[a].size();

    f(i, s) {
        if(!visited[l[a][i]]) {
            visited[l[a][i]] = true;
            dfs_l(l[a][i]);
        }
    }
}
void dfs_r(int a) {
    int s = r[a].size();

    f(i, s) {
        if(!visited[r[a][i]]) {
            visited[r[a][i]] = true;
            dfs_r(r[a][i]);
        }
    }
}
int get() {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(visited[i]) cnt++;
    }
    return cnt-1;
}

void solve() {
    int a, b;
    cin >> n >> m;
    l.resize(n+1); r.resize(n+1);
    
    f(i, m) {
        cin >> a >> b;
        l[a].emplace_back(b);
        r[b].emplace_back(a);
    }

    for(int i=1; i<=n; i++) {
        int re = n-1;

        memset(visited, 0, n+1);
        visited[i] = true;
        dfs_l(i);
        re -= get();

        memset(visited, 0, n+1);
        visited[i] = true;
        dfs_r(i);
        re -= get();

        cout << re << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}