#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 30408 (춘배가 선물하는 특별한 하트)
    solved by : minwoo0629a
*/

ll n, m;
priority_queue<ll, vector<ll>, greater<ll>> pq;
unordered_set<ll> used;

void solve() {
    cin >> n >> m;
    pq.emplace(n);

    while(!pq.empty()) {
        ll a = pq.top();
        pq.pop();

        if(a == m) {
            cout << "YES";
            return;
        }

        if(a/2 >= m && used.count(a/2) == 0) {pq.emplace(a/2); used.emplace(a/2);}
        if(a%2==1 && (a/2+1) >=m && used.count(a/2+1) == 0) {pq.emplace(a/2 + 1); used.emplace(a/2+1);}
    }
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}