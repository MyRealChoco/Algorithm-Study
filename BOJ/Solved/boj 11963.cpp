#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 11963 (High Card Low Card (Gold))
    solved by : minwoo0629a
*/

int n, re;
vector<int> v, g, l;
vector<bool> used;

bool comp(int a, int b) {
    return a > b;
}

void solve() {
    cin >> n;
    used.resize(2*n+1);

    int tmp;
    f(i, n) {
        cin >> tmp;
        used[tmp] = true;
        if(i<n/2) g.emplace_back(tmp);
        else l.emplace_back(tmp);
    }
    for(int i=1; i<=2*n; i++) if(!used[i]) v.emplace_back(i);

    sort(v.begin(), v.end());
    sort(g.begin(), g.end());
    sort(l.begin(), l.end(), comp);

    tmp = n/2;
    f(i, n/2) {
        while(tmp < n && v[tmp] < g[i]) tmp++;
        if(tmp < n && v[tmp++] > g[i]) re++;
    }
    tmp = n/2-1;
    f(i, n/2) {
        while(tmp > -1 && v[tmp] > l[i]) tmp--;
        if(tmp > -1 && v[tmp--] < l[i]) re++;
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}