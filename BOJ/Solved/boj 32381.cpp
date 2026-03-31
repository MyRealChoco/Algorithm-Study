#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 32381 (Coloring 2: Electric Boogaloo)
    solved by : minwoo0629a
*/

int n, q;
vector<ll> v, row, col, rowF, colF;
vector<pair<char, ll>> re;

void solve() {
    cin >> n >> q;
    v.resize(q);
    f(i, q) cin >> v[i];

    ll r, c, prev, nr, nc, tmp;
    r = c = prev = 0;
    nr = nc = 1;

    f(i, q) {
        ll d = v[i] - prev;

        if(r<n && d == n - 2*c) {
            if(!rowF.empty()) {
                tmp = rowF.back();
                rowF.pop_back();
            }
            else tmp = nr++;
            row.emplace_back(tmp);
            re.emplace_back('R', tmp);
            r++;
        }
        else if(r>0 && d == -(n - 2*c)) {
            tmp = row.back();
            row.pop_back();
            rowF.emplace_back(tmp);
            re.emplace_back('R', tmp);
            r--;
        }
        else if(c<n && d == n - 2*r) {
            if(!colF.empty()) {
                tmp = colF.back();
                colF.pop_back();
            }
            else tmp = nc++;
            col.emplace_back(tmp);
            re.emplace_back('C', tmp);
            c++;
        }
        else if(c>0 && d == -(n - 2*r)) {
            tmp = col.back();
            col.pop_back();
            colF.emplace_back(tmp);
            re.emplace_back('C', tmp);
            c--;
        }
        else {
            cout << -1;
            return;
        }

        prev = v[i];
    }

    for(auto &[a, b] : re) {
        cout << a << " " << b << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}