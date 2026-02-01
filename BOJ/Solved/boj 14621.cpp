#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14621 (나만 안되는 연애)
    solved by : minwoo0629a
*/

int n, m, re;
vector<bool> is_m;
vector<int> p;
vector<tuple<int, int, int>> v;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    cin >> n >> m;
    p.resize(n+1); is_m.resize(n+1, false);
    f(i, n+1) p[i] = i;

    char tmp;
    f(i, n) {
        cin >> tmp;
        if(tmp == 'M') is_m[i+1] = true;
    }
    int a, b, c;
    f(i, m) {
        cin >> a >> b >> c;
        v.emplace_back(c, a, b);
    }

    sort(v.begin(), v.end());
    f(i, m) {
        auto[c, a, b] = v[i];

        if(findP(a) != findP(b) && is_m[a] != is_m[b]) {
            re += c;
            p[findP(a)] = findP(b);
        }
    }

    int pa = findP(1);
    for(int i=2; i<=n; i++) {
        if(findP(i) != pa) {
            cout << -1;
            return;
        }
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}