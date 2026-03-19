#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 30463 (K-문자열)
    solved by : minwoo0629a
*/

int n, k;
ll re;
ll bit[1024];

void solve() {
    cin >> n >> k;

    int s;
    string tmp;
    f(i, n) {
        s = 0;
        cin >> tmp;
        f(j, 10) {
            s |= 1 << (tmp[j] - '0');
        }
        bit[s]++;
    }

    f(i, 1024) {
        if(!bit[i]) continue;
        for(int j=i; j<1024; j++) {
            if(!bit[j]) continue;
            if(__builtin_popcount(i|j) == k) {
                if(i==j) re += bit[i] * (bit[i]-1) / 2;
                else re += bit[i] * bit[j];
            }
        }
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}