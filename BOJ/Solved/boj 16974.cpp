#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16974 (레벨 햄버거)
    solved by : minwoo0629a
*/

ll n, x;
vector<pair<ll, ll>> v;

ll countP(ll lev, ll eat) {
    if(eat == 0) return 0;
    if(lev == 0) return 1;

    if(eat == v[lev-1].second+2) return v[lev-1].first+1;
    else if(eat <= v[lev-1].second+1) return countP(lev-1, eat-1);
    else return v[lev-1].first + 1 + countP(lev-1, eat-(v[lev-1].second + 2));
}

void solve() {
    cin >> n >> x;
    v.push_back({1, 1});

    for(int i=1; i<=n; i++) {
        ll p = v.back().first;
        ll n = v.back().second;
        v.push_back({2*p+1, 3+2*n});
    }

    cout << countP(n, x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}