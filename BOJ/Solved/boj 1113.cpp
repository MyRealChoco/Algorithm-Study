#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1113 (수영장 만들기)
    solved by : minwoo0629a
*/

int n, m, wall, res;
char p[50][51];
bool v[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> q;

void bfs(int x, int y) {
	q.clear();
	memset(v, 0, sizeof(bool)*50*50);

	int idx = 0, wall=10;
	v[y][x] = true;
	q.emplace_back(x, y);

	while(idx < q.size()) {
		auto[xt, yt] = q[idx];
		idx++;

		f(i, 4) {
			int xtt = xt + dx[i];
			int ytt = yt + dy[i];

			if(xtt<0 || ytt<0 || xtt>=m || ytt>=n) return;
			if(v[ytt][xtt]) continue;

			if(p[ytt][xtt] < p[y][x]) return;
			else if(p[ytt][xtt] > p[y][x]) {
				wall = min(wall, p[ytt][xtt]-'0');
			} else {
				v[ytt][xtt] = true;
				q.emplace_back(xtt, ytt);
			}
		}
	}

	res += q.size() * (wall - (p[y][x]-'0'));
	for(auto pp : q) {
		auto[xt, yt] = pp;
		p[yt][xt] = wall+'0';
	}
}

void search() {
	char t = '1';
	while(t<'9') {
		for(int i=1; i<n-1; i++) {
			for(int j=1; j<m-1; j++) {
				if(p[i][j] == t) {
					bfs(j, i);
				}
			}
		}
		t++;
	}
}

void solve() {
    cin >> n >> m;
    f(i, n) cin >> p[i];

    search();
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
} 