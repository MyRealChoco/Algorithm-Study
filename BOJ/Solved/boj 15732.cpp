#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 15732 (도토리 숨기기)
    solved by : minwoo0629a
*/

int n, k, d, re;
vector<tuple<int, int, int>> v;

ll count(int x) {
    ll tot=0;
    for(auto r : v) {
        auto[a, b, c] = r;
        if(a>x) continue;
        int m = min(b, x);
        tot += (ll)((m-a)/c) + 1LL;
        if(tot >= d) return tot;
    }
    return tot;
}

void solve() {
    cin >> n >> k >> d;
    f(i, k) {
        int a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(a, b, c);
    }

    int l=1, m , h=n;
    while(l<=h) {
        m = (l+h)/2;
        if(count(m) >= d){
            re = m;
            h = m-1;
        }
        else l = m+1;
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}