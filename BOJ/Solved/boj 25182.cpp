#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

#define MOD 1000000007

/*
    problem : boj 25182 (청정수열 (Hard))
    solved by : minwoo0629a
*/

int n;

void solve() {
    cin >> n;

    ll re1=0, re2=1;

    for(ll i=1; i<=n; i++) re1 = (re1 + (((i * i) % MOD) * (i + 1)) % MOD) % MOD;
    for(ll i=2; i<=n; i++) re2 = (((re2 * i) % MOD) * i) % MOD;

    cout << re1 << " " << re2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}