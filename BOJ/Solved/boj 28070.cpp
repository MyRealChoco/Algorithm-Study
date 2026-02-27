#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 28070 (유니의 편지 쓰기)
    solved by : minwoo0629a
*/

int n;
vector<int> v(96000, 0);

int c(int y, int m) {
    return (y-2000) * 12 + (m-1);
}

void solve() {
    cin >> n;

    int sy, sm, ey, em, l, r;
    char tmp;
    while(n--) {
        cin >> sy >> tmp >> sm >> ey >> tmp >> em;
        
        l = c(sy, sm);
        r = c(ey, em);
        v[l]++;
        if(r+1<96000) v[r+1]--;
    }

    int bestCnt = -1, bestIdx = 0, cur = 0;
    f(i, 96000) {
        cur += v[i];
        if (cur > bestCnt) {
            bestCnt = cur;
            bestIdx = i;
        }
    }

    int y = 2000 + bestIdx / 12;
    int m = bestIdx % 12 + 1;
    cout << y << "-" << (m < 10 ? "0" : "") << m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}