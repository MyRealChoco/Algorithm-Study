#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1833 (고속철도 설계하기)
    solved by : minwoo0629a
*/

int n, cost;
int p[201];
vector<tuple<int, int, int>> g;
vector<pair<int, int>> s;

int findP(int v){
    if(p[v] == v) return v;
    else return p[v] = findP(p[v]);
}

void solve() {
    cin >> n;
    f(i, n+1) p[i] = i;

    int tmp;
    f(i, n) f(j, n) {
        cin >> tmp;
        if(i >= j) continue;

        g.emplace_back(tmp, i, j);
    }
    sort(g.begin(), g.end());

    for(auto &[c, a, b] : g) {
        int pa = findP(a);
        int pb = findP(b);

        if(c<0) {
            p[pa] = pb;
            cost += abs(c);   
            continue;
        }

        if(pa != pb) {
            p[pa] = pb;
            cost += c;
            s.emplace_back(a+1, b+1);
        }
    }

    cout << "\n";
    int size = s.size();
    cout << cost << " " << size << '\n';
    f(i, size) {
        cout << s[i].first << " " << s[i].second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}