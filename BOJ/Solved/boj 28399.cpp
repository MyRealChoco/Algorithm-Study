#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 28399 (황혼)
    solved by : minwoo0629a
*/

int n, m, k;
vector<ll> re;
vector<vector<int>> sp;
vector<vector<pair<int, int>>> g;
map<tuple<int, int, int>, ll> dist;
unordered_map<int, int> mp;
priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<tuple<ll, int, int, int>>> pq;

void dijk() {
    dist.clear();

    auto it = mp.find(1);
    if(it == mp.end()) {
        dist[{1, -1, -1}] = 0;
        pq.emplace(0, 1, -1, -1);
    }
    else {
        dist[{1, it->second, 1}] = 0;
        pq.emplace(0, 1, it->second, 1);
    }
    
    while(!pq.empty()) {
        auto[cost, cur, flag, idx] = pq.top();
        pq.pop();

        if(cost > dist[{cur, flag, idx}]) continue;
        re[cur] = min(re[cur], cost);

        for(auto &[nxt, c] : g[cur]) {
            int nflag = -1, nidx = -1;

            if(flag == -1) {
                auto it = mp.find(nxt);
                if(it != mp.end()) {
                    nflag = it->second;
                    nidx = 1;
                }
            }
            else {
                if(sp[flag][idx+1] == nxt) {
                    if(sp[flag][0] == idx+1) continue;
                    nflag = flag;
                    nidx = idx+1;
                }
                else {
                    auto it = mp.find(nxt);
                    if(it != mp.end()) {
                        nflag = it->second;
                        nidx = 1;
                    }
                }
            }

            auto k = make_tuple(nxt, nflag, nidx);
            if(!dist.count(k) || cost + c < dist[k]) {
                dist[k] = cost+c;
                pq.emplace(cost+c, nxt, nflag, nidx);
            }
        }
    }

    for(int i=1; i<=n; i++) cout << (re[i] == LLONG_MAX ? -1 : re[i]) << " ";
}

void solve() {
    int u, v, w, s, tmp, idx=-1;
    cin >> n >> m >> k;
    re.resize(n+1, LLONG_MAX); g.resize(n+1); sp.resize(k);
    re[1] = 0;

    f(i, m) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    f(i, k) {
        cin >> s;
        f(j, s) {
            cin >> tmp;
            if(j==0) {
                mp.emplace(tmp, ++idx);
                sp[idx].emplace_back(s);
            }
            sp[idx].emplace_back(tmp);
        }
    }

    dijk();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}