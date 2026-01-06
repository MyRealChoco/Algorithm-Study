#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2564 (경비원)
    solved by : minwoo0629a
*/

int n, m, num, re;
vector<pair<int, int>> v;

void solve() {
    cin >> m >> n >> num;
    v.resize(num);

    f(i, num) cin >> v[i].first >> v[i].second;

    int dir, pos;
    cin >> dir >> pos;
    f(i, num) {
        auto[d, p] = v[i];
        if(d == dir) re += abs(pos-p);
        else if(d+dir <= 3) re += min(n + pos + p, n + (m-pos) + (m-p));
        else if(d+dir < 7) {
            if(dir == 1 && d == 3) re += pos + p;
            else if(dir == 1 && d == 4) re += (m-pos) + p;
            else if(dir == 2 && d == 3) re += pos + (n-p);
            else if(dir == 2 && d == 4) re += (m-pos) + (n-p);
            else if(dir == 3 && d == 1) re += pos + p;
            else if(dir == 3 && d == 2) re += (n-pos) + p;
            else if(dir == 4 && d == 1) re += pos + (m-p);
            else if(dir == 4 && d == 2) re += (n-pos) + (m-p);
        }
        else re += min(m + pos + p, m + (n-pos) + (n-p));
    }
    
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}