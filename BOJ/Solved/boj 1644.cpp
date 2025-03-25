#include <bits/stdc++.h>
using namespace std;

/*
problem : boj 1644 (소수의 연속합)
solved by : minwoo0629a
*/

int n;
vector<int> v;

void init() {
    bool visited[n+1];
    memset(visited, false, sizeof(bool)*(n+1));
    for(int i=2; i<=n; i++) {
        if(visited[i]) continue;
        v.push_back(i);
        for(int j=i+i; j<=n; j+=i) {
            visited[j] = true;
        }
    }
}

void solve() {
    cin >> n;
    if(n==1) {
        cout << 0;
        return;
    }

    init();
    
    int size = v.size();
    int r, l, sum, cnt;
    r = l = cnt = 0;
    sum = v[0];

    while(r < size && v[r] <= n) {
        if(sum < n) {
            if(++r < size && v[r] <= n) {
                sum += v[r];
            }
        }
        else if(sum == n){
            cnt++;
            sum += v[++r];
        }
        else {
            sum -= v[l++];
        }
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}