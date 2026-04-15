#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 23843 (콘센트)
    solved by : minwoo0629a
*/

int n, m;
vector<int> v;

void solve() {
    cin >> n >> m;
    v.resize(n);
    f(i, n) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> pq;
    f(i, m) pq.emplace(0);

    int re = 0;

    f(i, n) {
        int cur = pq.top();
        pq.pop();

        cur += v[i];
        re = max(re, cur);

        pq.emplace(cur);
    }
    
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}