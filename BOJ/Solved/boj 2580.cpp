#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2580 (스도쿠)
    solved by : minwoo0629a
*/

int n;
int yMask[9], xMask[9], bMask[9];
vector<vector<int>> s(9, vector<int>(9));
vector<pair<int, int>> v;

int getBox(int x, int y) {
    return 3 * (y/3) + (x/3);
}

bool bt() {
    int x=-1, y=-1, bestMask=0;
    int bestCnt=10;

    for (auto &[xt, yt] : v) {
        if (s[yt][xt] != 0) continue;

        int mask = yMask[yt] | xMask[xt] | bMask[getBox(xt, yt)];
        int cnt = 9 - __builtin_popcount(mask);

        if (cnt == 0) return false;
        if (cnt < bestCnt) {
            bestCnt = cnt;
            x = xt;
            y = yt;
            bestMask = mask;
            if (cnt == 1) break;
        }
    }
    if (x==-1) {
        f(i, 9) {f(j, 9) cout << s[i][j] << " "; cout << '\n';}
        return true;
    }

    int b = getBox(x, y);
    for(int i=1; i<10; i++) {
        int bit = 1 << i;
        if(bestMask & bit) continue;

        s[y][x] = i;
        yMask[y] |= bit;
        xMask[x] |= bit;
        bMask[b] |= bit;

        if(bt()) return true;
        else {
            s[y][x] = 0;
            yMask[y] ^= bit;
            xMask[x] ^= bit;
            bMask[b] ^= bit;
        }
    }

    return false;
}

void solve() {
    f(i, 9) f(j, 9) {
        cin >> s[i][j];
        if(s[i][j]) {
            int bit = 1 << s[i][j];
            yMask[i] |= bit;
            xMask[j] |= bit;
            bMask[getBox(j, i)] |= bit;
        }
        else v.emplace_back(j, i);
    }

    bt();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}