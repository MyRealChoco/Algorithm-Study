#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 12101 (1, 2, 3 더하기 2)
    solved by : minwoo0629a
*/

int n, cnt;
ll k;
bool f;
vector<int> v;

void bt(int sum) {
    if (sum == n) {
        cnt++;
        if (cnt == k) {
            int s = v.size();
            f(i, s) {
                cout << v[i];
                if (i != s - 1) cout << "+";
            }
            f = true;
            return;
        }
        return;
    }

    for(int i=1; i<=3; i++) {
        if (sum + i <= n) {
            v.push_back(i);
            bt(sum + i);
            v.pop_back();
        }
    }
}

void solve() {
    cin >> n >> k;
    bt(0);
    if(!f) cout << "-1";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}