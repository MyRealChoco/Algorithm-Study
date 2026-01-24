#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 14719 (빗물)
    solved by : minwoo0629a
*/

int h, w;
vector<vector<int>> v;

void rmv() {
    f(i, h) {
        f(j, w) {
            if(v[i][j]) break;
            v[i][j] = 1;
        }
        for(int j=w-1; j>-1; j--) {
            if(v[i][j]) break;
            v[i][j] = 1;
        }
    }
}

int chk() {
    int re = 0;
    f(i, h) f(j, w) if(!v[i][j]) re++;
    return re;
}

void solve() {
    cin >> h >> w;
    v.resize(h, vector<int>(w, 0));

    int tmp;
    f(i, w) {
        cin >> tmp;
        f(j, tmp) v[h-1-j][i] = 2;
    }

    rmv();
    cout << chk();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}