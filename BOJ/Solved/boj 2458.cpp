#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2458 (키 순서)
    solved by : minwoo0629a
*/

int n, m, cnt, re;
bool v[501];
vector<vector<int>> vl, vr;

void dfs_l(int c) {
    int size = vl[c].size();
    f(i, size) {
        if(v[vl[c][i]]) continue;
        cnt++;
        v[vl[c][i]] = true;
        dfs_l(vl[c][i]);
    }
}
void dfs_r(int c) {
    int size = vr[c].size();
    f(i, size) {
        if(v[vr[c][i]]) continue;
        cnt++;
        v[vr[c][i]] = true;
        dfs_r(vr[c][i]);
    }
}

void solve() {
    cin >> n >> m;
    vl.resize(n+1); vr.resize(n+1);
    
    int a, b;
    f(i, m) {
        cin >> a >> b;
        vl[b].emplace_back(a);
        vr[a].emplace_back(b);
    }

    for(int i=1; i<=n; i++) {
        cnt = 0;
        memset(v, 0, sizeof(bool)*(n+1));
        v[i] = true;
        dfs_l(i);
        dfs_r(i);

        if(cnt == n-1) re++;
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}