#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : 2819 (격자판의 숫자 이어 붙이기)
    solved by : 달콤초코
*/

typedef struct Node {
    int x, y, cnt, re;
}Node;

int m[4][4];
unordered_set<int> chk;
queue<Node> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void search() {
    f(i, 4) {
        f(j, 4) {
            q.push({j, i, 6, m[i][j]});

            while(!q.empty()) {
                int x = q.front().x;
                int y = q.front().y;
                int cnt = q.front().cnt;
                int re = q.front().re;
                q.pop();
                
                if(!cnt) {
                    chk.insert(re);
                    continue;
                }

                f(k, 4) {
                    int xt = x + dx[k];
                    int yt = y + dy[k];

                    if(xt<0 || xt>=4 || yt<0 || yt>=4) continue;
                    
                    q.push({xt, yt, cnt-1, re*10 + m[yt][xt]});
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case) {
        cout << "#" << test_case << " ";
        chk.clear();
        f(i,4) f(j,4) cin >> m[i][j];
        search();
        cout << chk.size() << "\n";
    }
    return 0;
}