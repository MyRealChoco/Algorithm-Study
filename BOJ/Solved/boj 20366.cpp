#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 20366 (같이 눈사람 만들래?)
    solved by : minwoo0629a
*/

int n, re=INT_MAX;
vector<int> v;

void solve() {
    cin >> n;
    v.resize(n);
    f(i,n) cin >> v[i];
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++) {
        for(int j=i+3; j<n; j++) {
            int s1 = v[i] + v[j];
            int l = i+1, r = j-1;
            while (l < r) {
                int s2 = v[l] + v[r];
                re = min(re, abs(s1 - s2));
                if(s2 < s1) l++;
                else r--;
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