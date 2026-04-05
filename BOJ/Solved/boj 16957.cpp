#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16957 (체스판 위의 공)
    solved by : minwoo0629a
*/

int r, c;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
vector<vector<int>> v, dp, re;
stack<pair<int, int>> st;

int h(int x, int y) {
    return x*1000 + y;
}
pair<int,int> rh(int a) {
    return make_pair(a/1000, a%1000);
}

void dfs(int x, int y) {
    int l, rx, ry;
    st.emplace(x, y);

    bool flag = false;
    while(!st.empty()) {
        auto [cx, cy] = st.top();
        if(flag) {
            dp[cy][cx] = dp[ry][rx];
            st.pop();
            continue;
        }

        l = INT_MAX; ry=cy; rx=cx;
        f(i, 8) {
            int xt = cx + dx[i];
            int yt = cy + dy[i];

            if(xt<0 || yt<0 || xt>=c || yt>=r) continue;
            
            if(v[yt][xt] < v[cy][cx] && v[yt][xt] < l) {
                l = v[yt][xt];
                rx = xt; ry = yt;
            }
        }

        if(l == INT_MAX) {
            dp[y][x] = h(cx, cy);
            re[cy][cx]++;
            st.pop();
            flag=true;
        } else {
            if(dp[ry][rx] != -1) {
                dp[cy][cx] = dp[ry][rx];
                auto [nx, ny] = rh(dp[ry][rx]);
                re[ny][nx]++;
                st.pop();
                flag=true;
            }
            else st.emplace(rx, ry);
        }
    }
}

void solve() {
    cin >> r >> c;
    v.resize(r, vector<int>(c)); dp.resize(r, vector<int>(c, -1)); re.resize(r, vector<int>(c, 0));
    f(i, r) f(j, c) cin >> v[i][j];

    f(i, r) f(j, c) dfs(j, i);

    f(i, r) {f(j, c) cout << re[i][j] << " "; cout << '\n';}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}