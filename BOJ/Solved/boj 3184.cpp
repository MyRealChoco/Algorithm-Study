#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
problem : boj 3184 (양)
solved by : minwoo0629a
*/

int r,c, re1, re2;
char maps[250][251];
bool visited[250][250];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    int a, b;
    a = b = 0;
    if(maps[y][x] == 'v') b++;
    else if(maps[y][x] == 'o') a++;
    
    q.push({x, y});
    visited[y][x] = true;

    while(!q.empty()) {
        int xtmp = q.front().first;
        int ytmp = q.front().second;
        q.pop();
        
        f(i, 4) {
            int xt = xtmp + dx[i];
            int yt = ytmp + dy[i];

            if(xt<0 || yt<0 || xt>=c || yt>=r) continue;
            if(visited[yt][xt] || maps[yt][xt] == '#') continue;
            
            if(maps[yt][xt] == 'o') a++;
            else if(maps[yt][xt] == 'v') b++;

            visited[yt][xt] = true;
            q.push({xt, yt});
        }
    }

    if(a<=b) a=0;
    if(a>b) b=0;

    re1 += a;
    re2 += b;
}

void find() {
    f(i, r) {
        f(j ,c) {
            if(!visited[i][j] && maps[i][j] != '#') {
                bfs(j, i);
                visited[i][j] = true;
            }
        }
    }
}

void solve() {
    cin >> r >> c;
    f(i, r) cin >> maps[i];
    find();
    cout << re1 << " " << re2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}