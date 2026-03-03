#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17265 (나의 인생에는 수학과 함께)
    solved by : minwoo0629a
*/

int n, re1 = -123123123, re2 = INT_MAX;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
vector<vector<char>> v;

int c(int a, char op, int b) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else return a * b;
}

void bfs() {
    queue<tuple<int, int, int, char>> q;
    q.emplace(0, 0, v[0][0] - '0', '.');

    while(!q.empty()) {
        auto[x, y, cur, op] = q.front();
        q.pop();

        if(x==n-1 && y==n-1) {
            re1 = max(re1, cur);
            re2 = min(re2, cur);
            continue;
        }

        f(i, 2) {
            int xt = x + dx[i];
            int yt = y + dy[i];

            if(xt<0 || yt<0 || xt>=n || yt>=n) continue;
            
            if(v[yt][xt] >= '0') q.emplace(xt, yt, c(cur, op, v[yt][xt]-'0'), '.');
            else q.emplace(xt, yt, cur, v[yt][xt]);
        }
    }
}

void solve() {
    cin >> n;
    v.resize(n, vector<char>(n));

    f(i, n) f(j, n) cin >> v[i][j];

    bfs();
    cout << re1 << " " << re2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}