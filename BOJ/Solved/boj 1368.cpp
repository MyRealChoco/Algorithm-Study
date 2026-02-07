#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1368 (물대기)
    solved by : minwoo0629a
*/

int n, re;
vector<int> p;
vector<tuple<int, int, int>> v;

int findP(int v){
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    cin >> n;
    p.resize(n+1);
    f(i, n+1) p[i] = i;

    int tmp;
    f(i, n) {
        cin >> tmp;
        v.emplace_back(tmp, n, i);
    }
    f(i, n) {
        f(j, n) {
            cin >> tmp;
            if(i==j) continue;
            v.emplace_back(tmp, i, j);
        }
    }
    sort(v.begin(), v.end());

    for(auto &[cost, a, b] :  v) {
        if(findP(a) != findP(b)) {
            p[findP(a)] = findP(b);
            re += cost;
        }
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}