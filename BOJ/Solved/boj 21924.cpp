#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 21924 (도시 건설)
    solved by : minwoo0629a
*/

bool compare(tuple<int, int, int> &a, tuple<int, int, int> &b) {
    return get<2>(a) < get<2>(b);
}

int n, m;
ll tot, re;
vector<int> parent;
vector<tuple<int, int, int>> v;

int findP(int v) {
    if(parent[v]==v) return v;
    else return parent[v] = findP(parent[v]);
}

void mst() {
    for(auto t : v) {
        auto[a,b,c] = t;
        if(findP(a) == findP(b)) continue;
        
        re += c;
        parent[findP(a)] = b;
    }
}

bool isConnected() {
    int tmp = findP(1);
    for(int i=2; i<=n; i++) {
        if(tmp != findP(i)) return false;
    }
    return true;
}

void solve() {
    int a, b, c;
    cin >> n >> m;
    f(i, m) {
        cin >> a >> b >> c;
        v.emplace_back(a, b, c);
        tot += c;
    }
    sort(v.begin(), v.end(), compare);

    parent.resize(n+1);
    f(i, n+1) parent[i] = i;

    mst();
    
    if(isConnected()) cout << tot-re;
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}