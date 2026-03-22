#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 9997 (폰트)
    solved by : minwoo0629a
*/

int n, re;
vector<int> v;

void bt(int bef, int s) {
    if(s == ((1<<26) - 1)) re++;

    for(int i=bef+1; i<n; i++) {
        bt(i, s | v[i]);
    }
}

void solve() {
    cin >> n;

    int size, t;
    string s;
    f(i, n) {
        cin >> s;
        t = 0;
        size = s.length();
        f(j, size) t |= 1 << (s[j]-'a');
        v.emplace_back(t);
    }

    bt(-1, 0);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}