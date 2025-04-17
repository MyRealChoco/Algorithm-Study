#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1339 (단어 수학)
    solved by : minwoo0629a
*/

int n, a[26];
vector<string> v;
vector<pair<int, int>> val;

void chk() {
    f(i, n) {
        int w = 1;
        string tmp = v[i];
        int len = tmp.length();
        for(int j = len-1; j>-1; j--) {
            a[tmp[j]-'A'] += w;
            w *= 10;
        }
    }
}

int calc() {
    int re = 0;
    f(i, 26) if(a[i]) val.push_back({a[i], i});

    sort(val.begin(), val.end(), greater<pair<int, int>>());
    int s = val.size();
    int n = 9;
    f(i, s) {
        re += val[i].first * n--;
    }
    return re;
}

void solve() {
    cin >> n;
    v.resize(n);

    f(i, n) cin >> v[i];

    chk();
    cout << calc();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}