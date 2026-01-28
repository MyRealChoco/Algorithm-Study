#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14950 (정복자)
    solved by : minwoo0629a
*/

int n, m, t, cnt, re;
vector<int> p;
vector<tuple<int, int, int>> v;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    cin >> n >> m >> t;
    p.resize(n+1);
    f(i, n+1) p[i] = i;

    int a, b, c;
    f(i, m) {
        cin >> a >> b >> c;
        v.emplace_back(c, a, b);
    }
    sort(v.begin(), v.end());

    f(i, m) {
        auto[cost, a, b] = v[i];
        
        if(findP(a) != findP(b)) {
            p[findP(a)] = findP(b);
            re += cost + t * cnt++;
        }
    }
    
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}