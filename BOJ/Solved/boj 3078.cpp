#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 3078 (좋은 친구)
    solved by : minwoo0629a
*/

int n, k;
ll re;
string s;
vector<int> in;
vector<int> v[21];

void solve() {
	cin >> n >> k;
	for(int i=2; i<21; i++) {v[i].resize(n); v[i][0]=0;}

	f(i, n) {
		cin >> s;
		int l = s.length();
		in.emplace_back(l);
		
		for(int j=2; j<21; j++) {
			if(j == l) v[j][i] = v[j][max(i-1, 0)] + 1;
			else v[j][i] = v[j][max(i-1, 0)];
		}
	}

	f(i, n) re += v[in[i]][min(i+k, n-1)] - v[in[i]][i];

	cout << re;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}