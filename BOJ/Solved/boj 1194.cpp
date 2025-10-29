#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 1194 (달이 차오른다, 가자.)
    solved by : minwoo0629a
*/

int n, m;
vector<string> maps;
bool visited[50][50][64];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isBetween(char target, char a, char b) {
    return target>=a && target<=b;
}
bool can_pass_door(char door, int keys) {
    int need = door - 'A';
    return (keys & (1 << need)) != 0;
}
int add_key(char key, int keys) {
    int bit = key - 'a';
    return keys | (1 << bit);
}

int bfs(int x, int y) {
    queue<tuple<int, int, int, int>> q; //x, y, key, dist
    q.emplace(x, y, 0, 0);
    visited[y][x][0] = true;

    while(!q.empty()) {
        auto[cx, cy, k, d] = q.front();
        q.pop();

        f(i, 4) {
            int nkey = k;
            int tx = cx + dx[i];
            int ty = cy + dy[i];
            
            if(tx < 0 || ty < 0 || tx >=m || ty >= n) continue; 

            char c = maps[ty][tx];
            if(c == '#') continue;
            if(c == '1') return d+1;
            if(isBetween(c, 'A', 'F')) {
                if(!can_pass_door(c, k)) continue;
            } 
            if(isBetween(c, 'a', 'f')) nkey = add_key(c, k);

            if(!visited[ty][tx][nkey]) {
                visited[ty][tx][nkey] = true;
                q.emplace(tx, ty, nkey, d+1);
            }
        }
    }
    return -1;
}


void solve() {
    int sx, sy;
    cin >> n >> m;
    maps.resize(n);
    f(i, n) {
        cin >> maps[i];
        f(j, m) if(maps[i][j] == '0') {sx = j; sy=i;}
    }
    cout << bfs(sx, sy);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}