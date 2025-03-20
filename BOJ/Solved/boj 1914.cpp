#include <bits/stdc++.h>
using namespace std;

/*
problem : boj 1914 (하노이 탑)
solved by : minwoo0629a
*/

void hanoi(int n, int st, int g, int tmp) {
    if(n==1) cout << st << " " << g << "\n";
    else {
        hanoi(n-1, st, tmp, g);
        cout << st << " " << g << "\n";
        hanoi(n-1, tmp, g, st);
    }
}

void solve() {
    int n;
    cin >> n;
    string k = to_string(pow(2, n));
    int idx = k.find('.');
    k = k.substr(0, idx);
    k[k.length() - 1] -= 1;

    cout << k << "\n";

    if(n<=20) hanoi(n, 1, 3, 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}