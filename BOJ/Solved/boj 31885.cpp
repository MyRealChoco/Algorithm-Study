#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 31885 (Yunny's Trip)
    solved by : minwoo0629a
*/

int n, k;
ll gx ,gy, re;
vector<pair<ll, ll>> v;
set<pair<ll, ll>> st;

bool isPT(ll x, ll y) {
    for(auto &p : v) {
        ll xt = x - p.first;
        ll yt = y - p.second;
        if(st.count({xt, yt})) return true;
    }
    return false;
}

void solve() {
    cin >> n >> k;
    v.resize(n);
    f(i, n) {cin >> v[i].first >> v[i].second; st.emplace(v[i]);}
    cin >> gx >> gy;

    // 0
    re = LLONG_MAX;
    ll c0 = llabs(gx) + llabs(gy);
    if(c0<=k) re = min(re, c0);

    // 1
    for(auto &p : v) {
        ll c1 = 2 + llabs(gx-p.first) + llabs(gy-p.second);
        if(c1 <= k) re = min(re, c1);
    }

    // 2
    if(k>=4) {
        if(isPT(gx, gy)) re = min(re, 4LL);

        if(k>=5) {
            if(isPT(gx+1, gy) || isPT(gx-1, gy) || isPT(gx, gy-1) || isPT(gx, gy+1)) re = min(re, 5LL);
        }
    }

    cout << (re == LLONG_MAX ? -1 : re); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}