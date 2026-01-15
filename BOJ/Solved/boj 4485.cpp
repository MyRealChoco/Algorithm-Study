#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 4485 (녹색 옷 입은 애가 젤다지?)
    solved by : minwoo0629a
*/

int n, re;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int m[125][125], v[125][125];

void dijk(int x, int y, int minus) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.emplace(minus, x, y);
    v[0][0] = m[0][0];
    
    while(!pq.empty()) {
        auto[cm, cx, cy] = pq.top();
        pq.pop();

        if(cm > v[cy][cx]) continue;
        if(cx == n-1 && cy == n-1) break;

        f(i, 4) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];
            
            if(xt<0 || yt<0 || xt>=n || yt>=n) continue;
            
            int mt = cm + m[yt][xt];
            if(mt < v[yt][xt]) {
                v[yt][xt] = mt;
                pq.emplace(mt, xt, yt);
            }
        }
    }
}

void solve() {
    for(int test_case=1; ; test_case++) {
        cin >> n;
        if(!n) return;

        re = INT_MAX;
        f(i, n) f(j, n) {cin >> m[i][j]; v[i][j] = INT_MAX;}

        dijk(0, 0, m[0][0]);
        cout << "Problem " << test_case << ": " << v[n-1][n-1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}