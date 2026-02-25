#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35279 (숫자 놀이 3)
    solved by : minwoo0629a
*/

int b, k;
ll lim = 10000000000000000LL;
vector<ll> pw;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solve() {
    cin >> b >> k;

    if (k <= b-1) {
        for(int i=1; i<=k; i++) cout << i << '\n';
        return;
    }

    ll tmp = 1;
    while(tmp <= LLONG_MAX / b) {pw.emplace_back(tmp); tmp *= b;}
    pw.emplace_back(lim + 1);

    ll maxLen = (ll)pw.size() - 1;

    for(int i=1; i<b; i++) pq.push(i);

    while (k > 0) {
        ll cur = pq.top(); pq.pop();
        cout << cur << '\n';
        k--;
    
        ll limLen = min(maxLen, lim/cur);
        for (ll len = 2; len <= limLen; len++) {
            ll nxt = cur * len;

            if (nxt >= pw[len-1] && nxt < pw[len]) {
                pq.push(nxt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    solve();
    return 0;
}
