#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
problem : boj 16724 (피리 부는 사나이)
solved by : minwoo0629a
*/

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int n, m, cnt;
bool visited[1000][1000];
vector<string> maps;

int change(char c) {
    switch(c) {
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'L':
            return 2;
        case 'R':
            return 3;
    }
    return -1;
}

void check(int x, int y) {
    //주변에서 나한테 오는 것
    for(int i=0; i<4; i++) {
        int xt = x + dx[i];
        int yt = y + dy[i];
        
        if(xt < 0 || yt < 0 || xt >= m || yt >= n) continue;
        if(visited[yt][xt]) continue;
        
        int idx = change(maps[yt][xt]);
        if((xt + dx[idx]) == x && (yt + dy[idx]) == y) {
            visited[yt][xt] = true;
            check(xt, yt);
        }
    }

    //내가 가는 방향
    int idx = change(maps[y][x]);
    int xt = x + dx[idx];
    int yt = y + dy[idx];
    
    if(xt < 0 || yt < 0 || xt >= m || yt >= n) return;
    if(visited[yt][xt]) return;

    visited[yt][xt] = true;
    check(xt, yt);
}

void find() {
    f(i, n) {
        f(j, m) {
            if(visited[i][j]) continue;

            visited[i][j] = true;
            check(j, i);
            cnt++;
        }
    }
}

void solve() {
    cin >> n >> m;
    f(i, n) {
        string tmp;
        cin >> tmp;
        maps.push_back(tmp);
    }

    find();
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}