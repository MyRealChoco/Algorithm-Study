#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 25556 (포스택)
    solved by : minwoo0629a
*/

int n;
stack<int> s[4];

void solve() {
    cin >> n;
    
    f(i, 4) s[i].emplace(0);
    int a, max, idx;
    f(i, n) {
        max = idx = -1;
        cin >> a;
        f(j, 4) {
            if(a > s[j].top() && s[j].top() > max) {max = s[j].top(); idx = j;}
        }
        if(idx == -1) {
            cout << "NO";
            return;
        } else s[idx].emplace(a);
    }
    cout << "YES";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}