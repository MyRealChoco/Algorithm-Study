#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 9335 (소셜 광고)
    solved by : minwoo0629a
*/

int t, n, d;
int visited[21];
vector<vector<int>> g;

bool bt(int bef, int cnt, int num) {
    if(cnt == num) {
        bool f = true;
        f(i, n) if(!visited[i+1]) f = false;
        return f;
    }

    for(int i=bef+1; i<=n; i++) {
        for(auto &n : g[i]) visited[n]++;
        if(bt(i, cnt+1, num)) return true;
        else for(auto &n : g[i]) visited[n]--;
    }

    return false;
}

void solve() {
    cin >> t;

    int tmp;
    while(t--) {
        memset(visited, 0, sizeof(visited));
        g.clear();
        cin >> n;
        g.resize(n+1);
        
        f(i, n) {
            cin >> d;
            
            g[i+1].emplace_back(i+1);
            f(j, d) {
                cin >> tmp;
                g[i+1].emplace_back(tmp);
            }
        }

        f(i, n) if(bt(0, 0, i+1)) {cout << i+1 << '\n'; break;}
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}