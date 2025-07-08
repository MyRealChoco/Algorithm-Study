#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;
 
/*
    problem : 1249 ([S/W 문제해결 응용] 4일차 - 보급로)
    solved by : 달콤초코
*/
 
typedef struct Node {
    int x, y, val;
    bool operator<(const Node b) const {
        return this->val > b.val;
    }
}Node;
 
int n;
int m[100][100];
int dp[100][100];
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
void bfs() {
    priority_queue<Node> pq;
    pq.push({0,0,0});
 
    while(!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int val = pq.top().val;
        pq.pop();
 
        f(i, 4) {
            int xt = x + dx[i];
            int yt = y + dy[i];
            if(xt<0 || xt>=n || yt<0 || yt>=n) continue;
 
            int vt = val + m[yt][xt];
            if(vt < dp[yt][xt]) {
                dp[yt][xt] = vt;
                pq.push({xt,yt,vt});
            }
        }
    }
}
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T;
    string s;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case) {
        cout << "#" << test_case << " ";
        cin >> n;
 
        f(i, n) {
            cin >> s;
            f(j, n) m[i][j] = s[j]-'0';
        }
        fill(&dp[0][0], &dp[n-1][n-1]+1, inf);
         
        bfs();
        cout << dp[n-1][n-1] << "\n";
    }
    return 0;
}