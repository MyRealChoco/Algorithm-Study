#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35424 (낙서 제거)
    solved by : minwoo0629a
*/

ll n, k, re;
vector<int> v;

void solve() {
    cin >> n >> k;
    v.resize(n);
    f(i, n) cin >> v[i];

    f(i, n) {
        ll t = 0;
        re++;
        ll mn, mx;
        mn = mx = v[i];
        for(int j=i+1; j<n; j++) {
            mn = min<ll>(mn, v[j]);
            mx = max<ll>(mx, v[j]);
            
            ll xt = mx - mn + 1;
            ll yt = j-i+1;

            if(xt*yt <= k) t++;
            else break;
        }
        i+=t;
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}