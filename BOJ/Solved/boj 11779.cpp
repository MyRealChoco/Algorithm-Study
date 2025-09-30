#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 11779 (최소비용 구하기 2)
    solved by : minwoo0629a
*/

int n, m, s, e;
ll dist[1001][2];
vector<int> path[1001];
vector<pair<int, int>> g[1001];
priority_queue<tuple<int, ll, int>, vector<tuple<int,ll, int>>, greater<tuple<int, ll, int>>> pq;

void find() {
    f(i, 1001) dist[i][0] = __LONG_LONG_MAX__;
    dist[s][0] = 0;
    pq.emplace(s, 0, 1);

    while(!pq.empty()) {
        auto[cur, cost, n] = pq.top();
        pq.pop();

        if(cost > dist[cur][0]) continue;
        int s = g[cur].size();
        f(i, s) {
            auto[nxt, c] = g[cur][i];
            if(dist[nxt][0] > cost + c) {
                dist[nxt][0] = cost+c;
                dist[nxt][1] = n+1;
                
                path[nxt].clear();
                path[nxt].push_back(cur);
                pq.emplace(nxt, cost + c, n+1);
            }
        }
    }
}

void tracking() {
    stack<int> st;
    st.push(e);
    while(true) {
        int tmp = st.top();
        st.push(path[tmp][0]);
        if(path[tmp][0] == s) {
            break;
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

void solve() {
    cin >> n >> m;
    f(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }    
    cin >> s >> e;
    find();
    cout << dist[e][0] << "\n" << dist[e][1] << "\n";
    tracking();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}