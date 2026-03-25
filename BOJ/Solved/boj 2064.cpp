#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2064 (IP 주소)
    solved by : minwoo0629a
*/

int n;

void solve() {
    cin >> n;

    char tmp;
    ll a, b, c, d;
    ll cur, mn, mx;
    mn = LLONG_MAX;
    mx = -1;

    f(i, n) {
        cin >> a >> tmp >> b >> tmp >> c >> tmp >> d;
        cur = (a<<24) + (b<<16) + (c<<8) + d;
        
        mn = min(mn, cur);
        mx = max(mx, cur);
    }

    ll diff = mx ^ mn;
    ll mask = 0;

    for(int i=31; i>-1; i--) {
        if(diff & (1LL<<i)) break;
        mask += 1LL<<i;
    }

    ll net = mn & mask;
    
    a = (net >> 24) & 255;
    b = (net >> 16) & 255;
    c = (net >> 8) & 255;
    d = net & 255;
    cout << a << '.' << b << '.' << c << '.' << d << '\n';

    a = (mask >> 24) & 255;
    b = (mask >> 16) & 255;
    c = (mask >> 8) & 255;
    d = mask & 255;
    cout << a << '.' << b << '.' << c << '.' << d << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}