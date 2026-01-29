#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 6497 (전력난)
    solved by : minwoo0629a
*/

int m, n;
int p[200000];
vector<tuple<int, int, int>> v;

int findP(int v) {
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    int x, y, z, re, sum;

    while(true) {
        v.clear();
        re = sum = 0;
        cin >> m >> n;
        if(!m && !n) break;

        f(i, m) p[i] = i;
        f(i, n) {
            cin >> x >> y >> z;
            v.emplace_back(z, x, y);
            sum += z;
        }
        sort(v.begin(), v.end());

        f(i, n) {
            auto[cost, a, b] = v[i];

            if(findP(a) != findP(b)) {
                p[findP(a)] = findP(b);
                re += cost;
            }
        }

        cout << sum-re << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}