#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 15644 (구슬 탈출 3)
    solved by : minwoo0629a
*/

bool visited[9000];
queue<tuple<int, int, int, int, int, string>> q;
int n, m, re=11, rx, ry, bx, by;
char board[10][11];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char a[4] = {'R', 'L', 'D', 'U'};

int uniq(int rx, int ry, int bx, int by) {
    return rx*1000 + ry*100 + bx*10 + by;
}

void check() {
    string tmp;
    int mv, rxt, ryt, bxt, byt;
    
    visited[uniq(rx, ry, bx, by)] = true;
    q.emplace(rx, ry, bx, by, 0, "");

    while(!q.empty()) {
        auto[rx, ry, bx, by, mv, rec] = q.front();
        mv++;
        q.pop();

        if(mv > 10) break;

        f(i, 4) {
            rxt = rx, ryt = ry, bxt = bx, byt = by;
            
            while(!(rxt==bxt && ryt==byt) && board[ryt][rxt] == '.') rxt+=dx[i], ryt+=dy[i];
            if(rxt == bxt && ryt == byt) {
                while(board[byt][bxt] == '.') bxt+=dx[i], byt+=dy[i];
                if(board[byt][bxt] == 'O') continue;
                bxt-=dx[i]; byt-=dy[i];
                rxt = bxt - dx[i], ryt = byt - dy[i];
            } else {
                if(board[ryt][rxt] == '#') rxt-=dx[i], ryt-=dy[i];

                while(!(bxt==rxt && byt==ryt) && board[byt][bxt] == '.') bxt+=dx[i], byt+=dy[i];
                if(board[byt][bxt] == 'O') continue;
                bxt-=dx[i]; byt-=dy[i];
            }
            
            if(board[ryt][rxt] == 'O') {
                cout << mv << "\n" << rec+a[i];
                return;
            }
            if(visited[uniq(rxt, ryt, bxt, byt)]) continue;
            visited[uniq(rxt, ryt, bxt, byt)] = true;
            if(mv<10) q.emplace(rxt, ryt, bxt, byt, mv, rec+a[i]);
        }
    }
    cout << -1;
}

void solve() {
    cin >> n >> m;
    f(i, n) f(j, m) {
        cin >> board[i][j];
        if(board[i][j] == 'R') rx = j, ry = i, board[i][j] = '.';
        else if(board[i][j] == 'B') bx = j, by = i, board[i][j] = '.';
    }
    check();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}