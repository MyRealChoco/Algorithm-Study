#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5972 (택배 배송)
    solved by : minwoo0629a
*/

int n, m;
vector<vector<pair<int, int>>> g;
vector<int> l;

void dijsk(int s) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    l[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()) {
        auto[val, loc] = pq.top();
        pq.pop();

        if(l[loc] < val) continue;

        int s = g[loc].size();
        f(i, s) {
            auto[v, lo] = g[loc][i];
            v += val;
            
            if(v < l[lo]) {
                l[lo] = v;
                pq.emplace(v, lo);
            }
        }
    }
}

void solve() {
    int a, b, c;
    cin >> n >> m;
    l.resize(n+1, INT_MAX);
    g.resize(n+1);

    f(i, m) {
        cin >> a >> b >> c;
        g[a].emplace_back(c, b);
        g[b].emplace_back(c, a);
    }

    dijsk(1);
    cout << l[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}