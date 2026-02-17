#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 6195 (Fence Repair)
    solved by : minwoo0629a
*/

int n;
ll re;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve() {
    cin >> n;

    int tmp;
    f(i, n) {
        cin >> tmp;
        pq.emplace(tmp);
    }

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        re += a + b;
        pq.emplace(a+b);
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}