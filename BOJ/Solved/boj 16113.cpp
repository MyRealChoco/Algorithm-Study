#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16113 (시그널)
    solved by : minwoo0629a
*/

vector<vector<char>> v;

int pattern[10][5][3] = {
    {   // 0
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {   // 1
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0},
        {1, 0, 0}
    },
    {   // 2
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1}
    },
    {   // 3
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    {   // 4
        {1, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {   // 5
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    },
    {   // 6
        {1, 1, 1},
        {1, 0, 0},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {   // 7
        {1, 1, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1},
        {0, 0, 1}
    },
    {   // 8
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    },
    {   // 9
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 0, 1},
        {1, 1, 1}
    }
};

void solve() {
    int n;
    cin >> n;
    v.resize(5, vector<char>(n/5));

    f(i, 5) f(j, n/5) cin >> v[i][j];
    f(i, n/5) {
        if(v[0][i] == '.') continue;

        bool flag[10] = {false, };
        f(j, 5) {
            for(int k=i; k<i+3; k++) {
                if(k >= n/5) {
                    f(l, 10) {
                        if(l==1) continue;
                        flag[l] = true;
                    }
                    break;
                }

                if((v[j][k] == '#' && !pattern[0][j][k-i]) || (v[j][k] == '.' && pattern[0][j][k-i])) flag[0] = true;
                if((v[j][k] == '#' && !pattern[1][j][k-i]) || (v[j][k] == '.' && pattern[1][j][k-i])) flag[1] = true;
                if((v[j][k] == '#' && !pattern[2][j][k-i]) || (v[j][k] == '.' && pattern[2][j][k-i])) flag[2] = true;
                if((v[j][k] == '#' && !pattern[3][j][k-i]) || (v[j][k] == '.' && pattern[3][j][k-i])) flag[3] = true;
                if((v[j][k] == '#' && !pattern[4][j][k-i]) || (v[j][k] == '.' && pattern[4][j][k-i])) flag[4] = true;
                if((v[j][k] == '#' && !pattern[5][j][k-i]) || (v[j][k] == '.' && pattern[5][j][k-i])) flag[5] = true;
                if((v[j][k] == '#' && !pattern[6][j][k-i]) || (v[j][k] == '.' && pattern[6][j][k-i])) flag[6] = true;
                if((v[j][k] == '#' && !pattern[7][j][k-i]) || (v[j][k] == '.' && pattern[7][j][k-i])) flag[7] = true;
                if((v[j][k] == '#' && !pattern[8][j][k-i]) || (v[j][k] == '.' && pattern[8][j][k-i])) flag[8] = true;
                if((v[j][k] == '#' && !pattern[9][j][k-i]) || (v[j][k] == '.' && pattern[9][j][k-i])) flag[9] = true;
            }
        }
        if(!flag[8]) {cout << 8; i+=2; continue;}
        if(!flag[9]) {cout << 9; i+=2; continue;}
        if(!flag[6]) {cout << 6; i+=2; continue;}
        if(!flag[0]) {cout << 0; i+=2; continue;}
        if(!flag[5]) {cout << 5; i+=2; continue;}
        if(!flag[3]) {cout << 3; i+=2; continue;}
        if(!flag[2]) {cout << 2; i+=2; continue;}
        if(!flag[4]) {cout << 4; i+=2; continue;}
        if(!flag[7]) {cout << 7; i+=2; continue;}
        if(!flag[1]) {cout << 1; i+=1; continue;}
        cout << 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}