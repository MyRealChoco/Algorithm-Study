#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5186 (파티를 열어라!!!)
    solved by : minwoo0629a
*/

int k, n, c, l;

int compare(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
}

void solve() {
    cin >> k;

    for(int test_num=1; test_num <= k; test_num++) {
        cin >> n >> c >> l;
        vector<pair<int, int>> v(l+1, {0, 0}), cart(c);

        int t1; char tmp;
        f(i, n) {
            cin >> t1 >> tmp;
            if(tmp=='I') v[t1].first++;
            else v[t1].second++;
        }
        f(i, c) cin >> cart[i].second >> cart[i].first;
        sort(cart.begin(), cart.end(), compare);

        f(i, c) {
            auto[num, loc] = cart[i];

            if(v[loc].second > 0) {
                v[loc].second--; num--;

                if(v[loc].first >= num) v[loc].first -= num;
                else {
                    num -= v[loc].first;
                    v[loc].first = 0;

                    v[loc].second = max(0, v[loc].second - num);
                }
            }
        }

        int re = 0;
        for(int i=1; i<=l; i++) re += v[i].first + v[i].second;
        cout << "Data Set " << test_num << ":\n" << re << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}