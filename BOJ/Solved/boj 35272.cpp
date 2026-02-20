#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35272 (사격 훈련)
    solved by : minwoo0629a
*/

int n;
double p, q, re;

double c(int a, int b) {
    double re = 1;
    f(i, b) re *= a--;
    while(b>0) re /= b--;
    return re;
}

void solve() {
    cin >> n >> p >> q;
    f(i, n+1) {
        double tmp = 0;
        for(int j=1; j<=n; j++) {
            for(int k=0; k<=i && k<=j; k++) {
                tmp += j * (c(i, k) * pow(p, k) * pow(1-p, i-k) *
                            c(n, j-k) * pow(q, j-k) * pow(1-q, n-(j-k)));
            }
            re = max(re, tmp);
        }
    }
    cout << fixed;
    cout.precision(15);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}