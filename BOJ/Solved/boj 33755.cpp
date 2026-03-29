#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 33755 (물류 작업 최적화)
    solved by : minwoo0629a
*/

int n;
vector<int> v, dpl, dpr;

void solve() {
    cin >> n;
    v.resize(n+1); dpl.resize(n+1); dpr.resize(n+2);
    dpl[0] = dpr[n+1] = 0;
    f(i, n) cin >> v[i+1];

    for(int i=1; i<=n; i++) dpl[i] = max(v[i], dpl[i-1] + v[i]);
    for(int i=n; i>0; i--) dpr[i] = max(v[i], dpr[i+1]+v[i]);
    
    for(int i=1; i<=n; i++) cout << dpl[i] + dpr[i] - v[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}