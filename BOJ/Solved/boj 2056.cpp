#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2056 (작업)
    solved by : minwoo0629a
*/

int n;
vector<int> deg, t, re;
vector<vector<int>> g;

void topol() {
    queue<int> q;

    for(int i=1; i<=n; i++) {
        if(deg[i] == 0) {
            q.emplace(i);
            re[i] = t[i];
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int nxt : g[cur]) {
            deg[nxt]--;
            re[nxt] = max(re[nxt], re[cur]);

            if(deg[nxt] == 0) {
                re[nxt] += t[nxt];
                q.emplace(nxt);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, re[i]);
    cout << ans;
}

void solve() {
    cin >> n;
    deg.resize(n+1); t.resize(n+1); re.resize(n+1, 0); g.resize(n+1);

    int tmp;
    for(int i=1; i<=n; i++) {
        cin >> t[i] >> deg[i];
        f(j, deg[i]) {
            cin >> tmp;
            g[tmp].emplace_back(i);
        }
    }

    topol();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}