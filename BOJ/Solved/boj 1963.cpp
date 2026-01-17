#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1963 (소수 경로)
    solved by : minwoo0629a
*/

int t;
int p[10001];
vector<int> v, dst;
vector<vector<int>> g;

int sim(int a, int b) {
    int cnt = 0;
    for(int d=1000; d>0; d/=10) {
        if(a/d == b/d) cnt++;
        a = a % d;
        b = b % d;
    }
    return cnt;
}

void bfs(int a, int b) {
    queue<int> q;
    fill(dst.begin(), dst.end(), -1);

    dst[a] = 0;
    q.emplace(a);

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == b) break;

        for(int nxt : g[cur]) {
            if(dst[nxt] == -1) {
                dst[nxt] = dst[cur] + 1;
                q.emplace(nxt);
            }
        }
    }

    if(dst[b] == -1) cout << "Impossible" << '\n';
    else cout << dst[b] << '\n';
}

void solve() {
    int a, b;
    for(int i=2; i<100; i++) {
        if(!p[i]) {
            for(int j=i+i; j<10001; j+=i) p[j] = 1;
        }
    }

    int idx = 0;
    for(int i=1000; i<10000; i++) {
        if(!p[i]) {
            p[i] = idx++;
            v.emplace_back(i);
        }
    }

    g.resize(idx); dst.resize(idx);

    f(i, idx) {
        for(int j=i+1; j<idx; j++) {
            if(sim(v[i], v[j]) == 3) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }

    cin >> t;
    while(t--) {
        cin >> a >> b;
        bfs(p[a], p[b]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}