#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1584 (게임)
    solved by : minwoo0629a
*/

int n, m;
int dist[501][501];
int mp[501][501];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dijk() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    dist[0][0] = 0;
    pq.emplace(0, 0, 0);

    while(!pq.empty()) {
        auto [cost, cx, cy] = pq.top();
        pq.pop();

        if(cost > dist[cy][cx]) continue;

        f(i, 4) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>500 || yt>500) continue;
            if(mp[yt][xt] == 2) continue;

            if(cost + mp[yt][xt] < dist[yt][xt]) {
                dist[yt][xt] = cost + mp[yt][xt];
                pq.emplace(cost + mp[yt][xt], xt, yt);
            }
        }
    }
}

void solve() {
    f(i, 501) f(j, 501) dist[i][j] = INT_MAX;

    cin >> n;

    int x1, y1, x2, y2, tmp;
    f(i, n) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {tmp = x1; x1 = x2; x2 = tmp;}
        if(y1 > y2) {tmp = y1; y1 = y2; y2 = tmp;}
        for(int y=y1; y<=y2; y++) {
            for(int x=x1; x<=x2; x++) {
                mp[y][x] = 1;
            }
        }
    }

    cin >> m;
    f(i, m) {
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {tmp = x1; x1 = x2; x2 = tmp;}
        if(y1 > y2) {tmp = y1; y1 = y2; y2 = tmp;}
        for(int y=y1; y<=y2; y++) {
            for(int x=x1; x<=x2; x++) {
                mp[y][x] = 2;
            }
        }
    }

    dijk();

    cout << (dist[500][500] == INT_MAX ? -1 : dist[500][500]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}