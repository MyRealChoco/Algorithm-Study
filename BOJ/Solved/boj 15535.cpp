#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 15535 (난로)
    solved by : minwoo0629a
*/

int n, k;
vector<int> t, g;

void solve() {
    cin >> n >> k;
    t.resize(n); g.resize(n);

    f(i, n) cin >> t[i];
    f(i, n-1) g[i] = t[i+1] - t[i] - 1;
    sort(g.begin(), g.end(), greater<int>());
    
    int re = t[n-1] - t[0] + 1;
    f(i, k-1) re -= g[i];
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}