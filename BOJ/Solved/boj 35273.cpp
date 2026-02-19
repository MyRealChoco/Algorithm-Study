#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35273 (착신 전환)
    solved by : minwoo0629a
*/

int n, dp[1000001], id[1000001];
bool visited[1000001];
vector<int> g;

void ts() {
    queue<int> q;
    vector<int> o;

    f(i, n) if(id[i+1] == 0) q.emplace(i+1);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        o.emplace_back(cur);

        int nxt = g[cur];
        id[nxt]--;
        if(id[nxt] == 0) q.emplace(nxt);
    }

    for(int i=1; i<=n; i++) {
        if(id[i] > 0 && !visited[i]) {
            int cur = i;
            while(!visited[cur]) {
                visited[cur] = true;
                dp[g[cur]] = cur;
                cur = g[cur];
            }
        }
    }

    int size = o.size();
    for(int i=size-1; i>-1; i--) dp[o[i]] = dp[g[o[i]]];
}

void solve() {
    cin >> n;
    g.resize(n+1);

    int tmp;
    f(i, n) {
        cin >> tmp;
        g[i+1] = tmp;
        id[tmp]++;
    }
    ts();
    f(i, n) cout << dp[i+1] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}