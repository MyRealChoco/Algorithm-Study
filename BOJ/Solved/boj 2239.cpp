#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
problem : boj 2239 (스도쿠)
solved by : minwoo0629a
*/

vector<string> sdoku(9);

bool l[9][10];
bool h[9][10]; 
bool s[9][10];

int chk_box_idx(int x, int y) {
    int re;
    
    if(y<3) re = 0;
    else if(y < 6) re = 3;
    else re = 6;

    if(x>5) re+=2;
    else if(x>2) re+=1;

    return re;
}

void init() {
    f(i, 9) {
        f(j, 9) {
            if(sdoku[i][j]!='0') {
                int v = sdoku[i][j] - '0';
                int b_idx = chk_box_idx(j, i);
                l[i][v] = true;
                h[j][v] = true;
                s[b_idx][v] = true;
            }
        }
    }
}

bool bt(int x, int y) {
    for(int i=y; i<9; i++) {
        for(int j = (i==y ? x : 0); j<9; j++) {
            if(sdoku[i][j] == '0') {
                int b_idx = chk_box_idx(j, i);
                
                for(int k=1; k<10; k++) {
                    if(!l[i][k] && !h[j][k] && !s[b_idx][k]) {
                        l[i][k] = h[j][k] = s[b_idx][k] = true;
                        sdoku[i][j] = '0' + k;
                        if(bt(j, i)) return true;            
                        l[i][k] = h[j][k] = s[b_idx][k] = false;
                        sdoku[i][j] = '0';
                    }
                }
                return false;         
            }
        }
    }

    return true;
}

void solve() {
    f(i, 9) cin >> sdoku[i];
    init();

    if(bt(0, 0)) f(i,9) cout << sdoku[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}