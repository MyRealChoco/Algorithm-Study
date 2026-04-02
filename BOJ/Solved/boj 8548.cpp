#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 8548 (Tarasy)
    solved by : minwoo0629a
*/

int n, k, bef, re;
vector<int> v, u, d;

void solve() {
    cin >> n >> k;
    v.resize(n); u.resize(n); d.resize(n);

    f(i, n) cin >> v[i];
    u[0] = 0;
    for(int i=1; i<n; i++) u[i] = u[i-1] + (v[i] > v[i-1] ? v[i]-v[i-1] : 0);
    d[n-1] = 0;
    for(int i=n-2; i>-1; i--) d[i] = d[i+1] + (v[i] > v[i+1] ? v[i]-v[i+1] : 0);

    int lp, rp;
    lp=0; rp=0;
    while(rp<n && lp<n) {
        if(u[rp] - u[lp] <= k) {
            re = max(re, rp-lp+1);
            rp++;
        }
        else lp++;
    }
    lp=n-1; rp=n-1;
    while(rp>-1 && lp>-1) {
        if(d[lp] - d[rp] <= k) {
            re = max(re, rp-lp+1);
            lp--;
        }
        else rp--;
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}