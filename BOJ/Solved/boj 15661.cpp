#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 15661 (링크와 스타트)
    solved by : minwoo0629a
*/

int n, re = INT_MAX;
vector<bool> used;
vector<vector<int>> v, s;

void bt(int idx) {
    if(idx == n) {
        int a, b, ca, cb;
        a = b = ca = cb = 0;

        f(i, n) {
            if(used[i]) ca++;
            else cb++;
        }

        if(!ca || !cb) return;

        f(i, n) {
            for(int j=i+1; j<n; j++) {
                if(used[i] && used[j]) a += s[i][j];
                else if(!used[i] && !used[j]) b += s[i][j];
            }
        }

        re = min(re, abs(a-b));
        return;
    }

    used[idx] = true;
    bt(idx+1);
    used[idx] = false;
    bt(idx+1);
}

void solve() {
    cin >> n;
    v.resize(n, vector<int>(n)); s.resize(n, vector<int>(n));
    used.resize(n, false);

    f(i, n) f(j, n) cin >> v[i][j];
    f(i, n) f(j, n) s[i][j] = v[i][j] + v[j][i];
    
    used[0] = true;
    bt(1);

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}