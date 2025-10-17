#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2589 (보물섬)
    solved by : minwoo0629a
*/

int a, b, re;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int t[50][50];
bool v[50][50];
vector<string> m;

void checkMax(int x, int y) {
    memset(t, 0, sizeof(int)*50*50);
    memset(v, false, sizeof(bool)*50*50);

    queue<pair<int, int>> q;
    q.emplace(x, y);
    v[y][x] = true;

    while(!q.empty()) {
        auto[cx, cy] = q.front();
        q.pop();

        f(i, 4) {
            int tx = cx + dx[i];
            int ty = cy + dy[i];

            if(tx<0 || ty<0 || tx>=b || ty>=a) continue;
            if(v[ty][tx] || m[ty][tx] == 'W') continue;

            t[ty][tx] = t[cy][cx] + 1;
            re = max(re, t[ty][tx]);
            
            v[ty][tx] = true;
            q.emplace(tx, ty);
        }
    }
}

void find() {
    f(y, a) {
        f(x, b) {
            if(m[y][x] == 'L') checkMax(x, y);
        }
    }
}

void solve() {
    cin >> a >> b;
    f(i, a) {
        string s;
        cin >> s;
        m.emplace_back(s);
    }

    find();
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}