#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16398 (행성 연결)
    solved by : minwoo0629a
*/

int n;
ll re;
vector<int> p;
vector<tuple<int, int, int>> v;

int compare(tuple<int,int,int> &a, tuple<int, int, int> &b) {
    return get<2>(a) < get<2>(b);
}

int getP(int v) {
    if(p[v] == v) return v;
    else return p[v] = getP(p[v]);
}

void mst() {
    int size = v.size();
    
    f(i, size) {
        auto[a, b, cost] = v[i];

        if(getP(a) != getP(b)) {
            re += cost;
            p[getP(a)] = b;
        }
    }
}

void solve() {
    cin >> n;
    p.resize(n);

    int tmp;
    f(i, n) {
        f(j, n) {
            cin >> tmp;
            if(j<=i) continue;

            v.emplace_back(i, j, tmp);
        }
    }

    sort(v.begin(), v.end(), compare);
    f(i, n) p[i] = i;

    mst();
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}