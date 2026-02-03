#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 13904 (과제)
    solved by : minwoo0629a
*/

int n;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

void solve() {
    cin >> n;
    v.resize(n);

    f(i, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        pq.emplace(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }

    int re=0;
    while(!pq.empty()) {
        re += pq.top();
        pq.pop();
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}