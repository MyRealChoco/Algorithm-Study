#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5624 (좋은 수)
    solved by : minwoo0629a
*/

int n, re;
unordered_set<ll> v, t;

void solve() {
    cin >> n;
    
    ll tmp;
    f(i, n) {
        cin >> tmp;
        for(ll x : v) {
            if(t.count(tmp-x)) {
                re++;
                break;
            }
        }

        if(v.count(tmp) == 0) {
            v.emplace(tmp);
            for(ll x : v) t.emplace(tmp + x);
        }
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}