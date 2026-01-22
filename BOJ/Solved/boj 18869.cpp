#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 18869 (멀티버스 Ⅱ)
    solved by : minwoo0629a
*/

int n, m, re;
vector<vector<pair<int, int>>> v;

void solve() {
    cin >> n >> m;
    v.resize(n, vector<pair<int,int>>(m, {-1, -1}));
    
    f(i, n) f(j, m) {
        cin >> v[i][j].first;
        v[i][j].second = j;
    }

    f(i, n) sort(v[i].begin(), v[i].end());

    f(i, n) {
        for(int j=i+1; j<n; j++) {
            bool f = true;
            f(k, m) {
                if(v[i][k].second != v[j][k].second) {
                    f = false;
                    break;
                }
                if(k>0 && ((v[i][k-1].first == v[i][k].first) != (v[j][k-1].first == v[j][k].first))){
                    f = false;
                    break;
                }
            }
            if(f) re++;
        }
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}