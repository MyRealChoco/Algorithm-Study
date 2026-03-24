#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 20293 (연료가 부족해)
    solved by : minwoo0629a
*/

int r, c, n, sz;
vector<tuple<int, int, int>> v;

bool is_p(int f) {
    vector<int> dp(sz, -1);
    dp[0] = f;

    f(i, sz) {
        if(dp[i] < 0) continue;
        auto[x1, y1, f1] = v[i];

        for(int j=i+1; j<sz; j++) {
            auto[x2, y2, f2] = v[j];
            if(x1>x2 || y1>y2) continue;

            int dist = x2-x1 + y2-y1;
            if(dp[i] >= dist) {
                dp[j] = max(dp[j], dp[i]-dist+f2);
            }
        }
    }

    return dp.back() > -1;
}

void bs() {
    int l=0, m, h=r+c, re=INT_MAX;

    while(l<=h) {
        m = (l+h)/2;

        if(is_p(m)) {
            re = min(re, m);
            h = m-1;
        }
        else l = m+1;
    }

    cout << re;
}

void solve() {
    cin >> r >> c >> n;
    v.emplace_back(1, 1, 0);

    int x, y, d;
    f(i, n) {
        cin >> y >> x >> d;
        v.emplace_back(x, y, d);
    }
    v.emplace_back(c, r, 0);
    
    sort(v.begin(), v.end());
    sz = v.size();

    bs();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}