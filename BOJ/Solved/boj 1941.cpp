#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1941 (소문난 칠공주)
    solved by : minwoo0629a
*/

int re;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int picked[7];
bool sel[5][5], visited[5][5];
queue<pair<int, int>> q;
vector<string> m(5);

bool check() {
    int cnt = 0;
    memset(visited, 0, sizeof(bool)*25);
    
    q.emplace(picked[0]%5, picked[0]/5);
    visited[picked[0]/5][picked[0]%5] = true;
    cnt++;

    while(!q.empty()) {
        auto[cx, cy] = q.front();
        q.pop();

        f(i, 4) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>=5 || yt>=5) continue;
            if(!sel[yt][xt]) continue;
            if(visited[yt][xt]) continue;

            visited[yt][xt] = true;
            cnt++;
            q.emplace(xt, yt);
        }
    }

    return cnt == 7;
}

void bt(int idx, int bef, int scnt, int ycnt) {
    if(ycnt > 3) return;
    if(scnt + ycnt == 7) {
        if(scnt > ycnt && check()) re++;
        return;
    }

    for(int i=bef+1; i<25; i++) {
        picked[idx] = i;
        sel[i/5][i%5] = true;
        if(m[i/5][i%5] == 'S') bt(idx+1, i, scnt+1, ycnt);
        else bt(idx+1, i, scnt, ycnt+1);
        sel[i/5][i%5] = false;
    }
}

void solve() {
    f(i, 5) cin >> m[i];
    bt(0, -1, 0, 0);
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}