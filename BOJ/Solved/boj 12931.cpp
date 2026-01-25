#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 12931 (두 배 더하기)
    solved by : minwoo0629a
*/

int n, re;
vector<int> v;

bool isDone() {
    f(i, n) if(v[i]) return false;
    return true;
}
void d2() {
    if(isDone()) return;
    re++;
    f(i, n) v[i] = v[i]/2;
}
bool rm_d() {
    bool flag = false;
    f(i, n) {
        if(v[i]%2) {
            flag = true;
            v[i]--;
            re++;
        }
    }
    return flag;
}

void grd() {
    while(!isDone()) {
        rm_d();
        d2();
    }
}

void solve() {
    cin >> n;
    v.resize(n);

    f(i, n) cin >> v[i];

    grd();
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}