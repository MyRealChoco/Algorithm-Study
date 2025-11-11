#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 27971 (강아지는 많을수록 좋다)
    solved by : minwoo0629a
*/

int n, m;
int dx[2];
bool visited[100001];

void bfs() {
    int re = INT_MAX;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    
    while(!q.empty()) {
        auto[x, cnt] = q.front();
        q.pop();

        f(i, 2) {
            int xt = x + dx[i];
            
            if(xt > n || visited[xt]) continue;
            if(xt == n) {
                re = min(re, cnt+1);
                continue;
            }

            visited[xt] = true;
            q.emplace(xt, cnt+1);
        }
    }

    cout << (re == INT_MAX ? -1 : re);
}

void solve() {
    int at, bt;
    cin >> n >> m >> dx[0] >> dx[1];
    
    f(i, m) {
        cin >> at >> bt;
        for(int j=at; j<=bt; j++) visited[j] = true;
    }

    bfs();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}