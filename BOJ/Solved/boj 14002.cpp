#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14002 (가장 긴 증가하는 부분 수열 4)
    solved by : minwoo0629a
*/

int n;
vector<int> v, dp, bef;

void solve() {
    cin >> n;
    v.resize(n); dp.resize(n, 1); bef.resize(n, -1);

    f(i, n) cin >> v[i];

    int len=1, end=0;
    f(i, n) {
        f(j, i) {
            if(v[i] > v[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j]+1;
                bef[i] = j;
            }
        }
        if(dp[i] > len) {
            len = dp[i];
            end = i;
        }
    }
    
    cout << len << '\n';
    stack<int> s;
    for(int idx=end; idx!=-1; idx=bef[idx]) s.emplace(v[idx]);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}