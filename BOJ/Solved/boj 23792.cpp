#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 23792 (K번째 음식 찾기 2)
    solved by : minwoo0629a
*/

int n, q;
vector<int> c1, c2, c3;
vector<pair<int, int>> s;
vector<vector<ll>> v(3);

void pre() {
    int p1, p2, p3, ci, total = 3*n;
    ci = p1 = p2 = p3 = 0;
    while (ci < total) {
        ll a = (p1 < n ? v[0][p1] : LLONG_MAX);
        ll b = (p2 < n ? v[1][p2] : LLONG_MAX);
        ll c = (p3 < n ? v[2][p3] : LLONG_MAX);

        if (a < b && a < c) {
            s[ci].first = 1;
            s[ci].second = p1+1;
            p1++;
        } else if (b < c) {
            s[ci].first = 2;
            s[ci].second = p2+1;
            p2++;
        } else {
            s[ci].first = 3;
            s[ci].second = p3+1;
            p3++;
        }

        c1[ci] = p1;
        c2[ci] = p2;
        c3[ci] = p3;
        ci++;
    }
}

void solve() {
    ll tmp;
    cin >> n;
    c1.resize(3*n); c2.resize(3*n); c3.resize(3*n); s.resize(3*n);
    f(i, 3) f(j, n) {cin >> tmp; v[i].emplace_back(tmp);}

    pre();

    int x, y, z, k, l, m, h;
    cin >> q;
    while(q--) {
        cin >> x >> y >> z >> k;

        l=0; h=3*n-1;
        while(l<h) {
            m = (l+h)/2;

            if(min(x, c1[m]) + min(y, c2[m]) + min(z, c3[m]) >= k) h = m;
            else l = m+1;
        }
        cout << s[l].first << " " << s[l].second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}