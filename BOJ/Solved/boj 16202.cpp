#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16202 (MST 게임)
    solved by : minwoo0629a
*/

int m, n, k, re;
vector<tuple<int, int, int>> v;
int parent[1001];

int findP(int v) {
	if(parent[v] == v) return v;
	else return parent[v] = findP(parent[v]);
}

bool isConnected() {
	int tmp = findP(1);
	for(int i=2; i<n; i++) {
		if(findP(i) != tmp) return false;
	}
	return true;
}

void mst(int t) {
	re = 0;
	f(i, n+1) parent[i] = i;

	for(int i=t; i<m; i++) {
		auto[a, b, c] = v[i];
		
		int pa = findP(a);
		int pb = findP(b);
		
		if(pa != pb) {
			parent[pa] = pb;
			re += c;
		} 
	}
}

void solve() {
	int a, b;
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++) {
		cin >> a >> b;
		v.emplace_back(a, b, i);
	}
	
	bool f=true;
	f(i, k) {
		if(!f) {cout << "0 "; continue;}
		
		mst(i);
		if(!isConnected()) {f = false; cout << "0 ";}
		else cout << re << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}