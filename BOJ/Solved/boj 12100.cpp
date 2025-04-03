#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
problem : boj 12100 (2048 (Easy))
solved by : minwoo0629a
*/

// 경우의 수 : 4^5 = 1024

int n, max_n;

vector<vector<int>> move(vector<vector<int>> b, int cur_mode) {
    vector<vector<int>> tmp(b);

    switch(cur_mode) {
    case 0:
        for(int x=n-1; x>-1; x--) {
            for(int y=0; y<n; y++) {
                if(!tmp[y][x]) {
                    int tx = x;
                    while(--tx>-1) {
                        if(tmp[y][tx]) {
                            swap(tmp[y][tx], tmp[y][x]);
                            break;
                        }
                    }
                    if(!tmp[y][x]) continue;
                }

                for(int tx=x-1; tx>-1; tx--) {
                    if(tmp[y][tx]) {
                        if(tmp[y][tx] == tmp[y][x]) {
                            tmp[y][x] *= 2;
                            tmp[y][tx] = 0;
                        }
                        break;
                    }
                }
            }
        }
        break;

    case 1:
        for(int x=0; x<n; x++) {
            for(int y=0; y<n; y++) {
                if(!tmp[y][x]) {
                    int tx = x;
                    while(++tx<n) {
                        if(tmp[y][tx]) {
                            swap(tmp[y][tx], tmp[y][x]);
                            break;
                        }
                    }
                    if(!tmp[y][x]) continue;
                }

                for(int tx=x+1; tx<n; tx++) {
                    if(tmp[y][tx]) {
                        if(tmp[y][tx] == tmp[y][x]) {
                            tmp[y][x] *= 2;
                            tmp[y][tx] = 0;
                        }
                        break;
                    }
                }
            }
        }
        break;
    case 2:
        for(int y=n-1; y>-1; y--) {
            for(int x=0; x<n; x++) {
                if(!tmp[y][x]) {
                    int ty = y;
                    while(--ty>-1) {
                        if(tmp[ty][x]) {
                            swap(tmp[ty][x], tmp[y][x]);
                            break;
                        }
                    }
                    if(!tmp[y][x]) continue;
                }

                for(int ty = y-1; ty > -1; ty--) {
                    if(tmp[ty][x]) {
                        if(tmp[ty][x] == tmp[y][x]) {
                            tmp[y][x] *= 2;
                            tmp[ty][x] = 0;
                        }
                        break;
                    }
                }
            }
        }
        break;
    case 3:
        for(int y=0; y<n; y++) {
            for(int x=0; x<n; x++) {
                if(!tmp[y][x]) {
                    int ty = y;
                    while(++ty < n) {
                        if(tmp[ty][x]) {
                            swap(tmp[ty][x], tmp[y][x]);
                            break;
                        }
                    }
                    if(!tmp[y][x]) continue;
                }

                for(int ty = y+1; ty<n; ty++) {
                    if(tmp[ty][x]) {
                        if(tmp[ty][x] == tmp[y][x]) {
                            tmp[y][x] *= 2;
                            tmp[ty][x] = 0;
                        }
                        break;
                    }
                }
            }
        }   
    }
    return tmp;
}

int chk_max(vector<vector<int>> b) {
    int m=0;
    f(i, n) f(j, n) m = max(m, b[i][j]);
    return m;
}

void bfs(vector<vector<int>> b, int cnt) {
    if(cnt == 0) {
        max_n = max(max_n, chk_max(b));
        return;
    }

    vector<vector<int>> tmp;
    for(int i=0; i<4; i++) {
        tmp = move(b, i);
        bfs(tmp, cnt-1);  
    }
}

void solve() {
    cin >> n;
    vector<vector<int>> b(n);
    
    f(i, n) {
        f(j, n) {
            int tmp;
            cin >> tmp;
            b[i].push_back(tmp);
        }
    }

    bfs(b, 5);
    cout << max_n;
 }
 
 int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
 }