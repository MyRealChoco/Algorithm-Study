#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 9024 (두 수의 합)
    solved by : minwoo0629a
*/

int t, n, k, gap, re;
int in[1000000];

void solve() {
    cin >> t;
    while(t--) {
        re = 0; gap = INT_MAX;
        cin >> n >> k;
        f(i, n) cin >> in[i];
        sort(in, in + n);
        
        int l = 0, r = n-1;
        while(l < r) {
            int s = in[l] + in[r];
            int g = abs(k-s);

            if(g<gap) {
                gap = g;
                re = 1;
            }
            else if(g == gap) re++;

            if(s < k) l++;
            else if(s > k) r--;
            else {
                l++;
                r--;
            }
        }

        cout << re << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}