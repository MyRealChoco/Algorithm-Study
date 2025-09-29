#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16932 (모양 만들기)
    solved by : minwoo0629a
*/

int n, m, re, idx;
int s[1000][1000];
bool visited[1000][1000];
int cv[250001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<tuple<int, int>> q;
vector<int> v;

void check(int x, int y) {
    int r = 1;
    idx++;
    
    visited[y][x] = true;
    s[y][x] = idx;
    q.emplace(x, y);

    while(!q.empty()) {
        auto[xt, yt] = q.front();
        q.pop();

        f(i, 4) {
            int xtt = xt + dx[i];
            int ytt = yt + dy[i];

            if(xtt<0||ytt<0||xtt>=m||ytt>=n) continue;
            if(visited[ytt][xtt] || !s[ytt][xtt]) continue;

            r++;
            visited[ytt][xtt] = true;
            s[ytt][xtt] = idx;
            q.emplace(xtt, ytt);
        }
    }

    v.push_back(r);
}

void solve() {
    cin >> n >> m;
    f(i, n) f(j, m) cin >> s[i][j];
    f(i, n) f(j, m) if(s[i][j] && !visited[i][j]) check(j, i);
    
    int turn = 0;
    f(i, n) {
        f(j, m) {
            if(!s[i][j]) {
                turn++;
                int tmp = 1;
                f(k, 4) {
                    int xt = j + dx[k];
                    int yt = i + dy[k];
                    if(xt<0||yt<0||xt>=m||yt>=n) continue;
                    if(!s[yt][xt]) continue;
                    if(cv[s[yt][xt]] == turn) continue;
                    
                    cv[s[yt][xt]] = turn;
                    tmp += v[s[yt][xt]-1];
                }
                re = max(re, tmp);
            }
        }
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}