#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16562 (친구비)
    solved by : minwoo0629a
*/

int n, m, k, re;
vector<int> cost, p;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    int a, b;
    cin >> n >> m >> k;
    cost.resize(n); p.resize(n+1);
    f(i, n+1) p[i] = i;

    f(i, n) cin >> cost[i];
    f(i, m) {
        cin >> a >> b;
        if(a==b) continue;

        if(findP(a) != findP(b)) {
            p[findP(b)] = findP(a);
        }
    }

    unordered_map<int, int> s;
    for(int i=1; i<=n; i++) {
        int cur = findP(i);
        if(s.find(cur) != s.end()) {
            if(cost[i-1] < s.find(cur)->second) s.find(cur)->second = cost[i-1];
        } else {
            s.emplace(cur, cost[i-1]);
        }
    }
    for(auto i : s) re += i.second;
    if(re > k) cout << "Oh no";
    else cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}