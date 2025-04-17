#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1715 (카드 정렬하기)
    solved by : minwoo0629a
*/

priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
    int n, tmp, re=0;
    cin >> n;
    f(i, n) {
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b =  pq.top();
        pq.pop();
        
        re += a+b;
        pq.push(a+b);
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}