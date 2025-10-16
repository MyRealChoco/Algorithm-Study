#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 10868 (최솟값)
    solved by : minwoo0629a
*/

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n): n(n) {
        tree.assign(4 * n, INT_MAX); 
    }

    void build(const vector<int>& a, int node, int s, int e) {
        if (s == e) {tree[node] = a[s]; return;}

        int mid = (s + e) / 2;
        build(a, node * 2, s, mid);
        build(a, node * 2 + 1, mid + 1, e);

        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return INT_MAX;
        if (l <= s && e <= r) return tree[node];

        int mid = (s + e) / 2;
        int leftMin = query(node * 2, s, mid, l, r);
        int rightMin = query(node * 2 + 1, mid + 1, e, l, r);
        return min(leftMin, rightMin);
    }
};

int n, m;
vector<int> v;

void solve() {
	cin >> n >> m;

    v.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    SegTree seg(n);
    seg.build(v, 1, 1, n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << seg.query(1, 1, n, a, b) << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}