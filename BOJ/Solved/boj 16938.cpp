#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

int n, l, r, x, re;
vector<int> v;

void bt(int st_idx, int min, int sum) {
    if(sum > r) return;

    for(int i=st_idx+1; i<n; i++) {
        int tmp = v[i];
    
        if(sum+tmp >= l && sum+tmp <= r && min != -1 && v[i]-min >= x) re++;
        min == -1 ? bt(i, v[i], sum+tmp) : bt(i, min, sum+tmp);
    }
}

void solve() {
    cin >> n >> l >> r >> x;
    v.resize(n);
    f(i, n) cin >> v[i];

    sort(v.begin(), v.end());
    bt(-1, -1, 0);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}