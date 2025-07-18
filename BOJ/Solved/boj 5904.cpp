#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 5904 (Moo 게임)
    solved by : minwoo0629a
*/

int n;
string s = "moo";

void func(int k, int l) {
    if(k==0) {cout << s[n-1]; return;}
    int bef = (l - (k+3)) / 2;

    if(n <= bef) func(k-1, bef);
    else if(n<=bef+(k+3)) {
        if(n == bef+1) cout << "m";
        else cout << "o";
        return;
    }
    else {
        n-=(bef+k+3);
        func(k-1, bef);
    }
}

void solve() {
    cin >> n;
    int k=0, l=3;
    while(l<n) {
        k++;
        l = l*2 + k+3;
    }
    func(k, l); 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}