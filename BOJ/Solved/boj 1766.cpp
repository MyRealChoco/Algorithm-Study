#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1766 (문제집)
    solved by : minwoo0629a
*/

int n,m,top=-1;
int p[32001];
vector<int> g[32001];
priority_queue<int, vector<int>, greater<int>> q;

void find() {
	int cur,size;
	for(int i=1;i<=n;i++) {
		if(!p[i]) q.push(i);
	}
	while(!q.empty()) {
		cur = q.top();
		cout << cur << ' ';
		q.pop();

		size = g[cur].size();
		f(i, size) {
			p[g[cur][i]]--;
			if(!p[g[cur][i]]) {
				q.push(g[cur][i]);
			}
		}
	}
}

void solve() {
	int t1,t2;
	cin >> n >> m;

	f(i, m) {
		cin >> t1 >> t2;
		g[t1].push_back(t2);
		p[t2]++;
	}

	find();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}