#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
problem : boj 1052 (물병)
solved by : minwoo0629a
*/

int n, k;

int find_max(int a) {
    int tmp;
    for(int i=0; ; i++) {
        if(a < pow(2, i)) break;
        tmp = pow(2, i);
    }
    return tmp;
}

void solve() {
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(n>0) {
        int tmp = find_max(n);
        pq.push(tmp);
        n -= tmp;
    }    

    int cnt = 0;
    while(pq.size() > k) {
        int first = pq.top();
        pq.pop();

        if(first == pq.top()) {
            pq.pop();
            pq.push(first*2);
        } else {
            cnt += pq.top() - first;
            pq.push(pq.top()*2);
            pq.pop();
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}