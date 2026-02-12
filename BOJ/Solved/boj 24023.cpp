#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 24023 (아기 홍윤)
    solved by : minwoo0629a
*/

int n, k;

void solve() {
    cin >> n >> k;

    int tmp, s, cur=0;
    s = -1;
    for(int i=1; i<=n; i++) {
        cin >> tmp;
        if((tmp | k) > k) {s = -1; cur = 0;}
        else {
            cur = cur | tmp;
            if(s == -1) s = i;
            
            if(cur == k) {
                cout << s << " " << i;
                return;
            }
        }
    }
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}