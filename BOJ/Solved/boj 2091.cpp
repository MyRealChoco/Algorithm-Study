#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2091 (동전)
    solved by : minwoo0629a
*/

int x, a, b, c, d;
int r1, r2, r3, r4;

void solve() {
    cin >> x >> a >> b >> c >> d;

    int best = -1;
    int lim4 = min(d, x/25);
    for(int i=0; i<=lim4; i++) {
        int left4 = x - 25*i;
        int lim3 = min(c, left4/10);

        for(int j=0; j<=lim3; j++) {
            int left3 = left4 - 10*j;

            int lo = max(0, (left3-a + 4) / 5);
            int hi = min(b, left3 / 5);
            if(lo > hi) continue;

            int k = lo;
            int l = left3 - 5*k;
            int cnt = i + j + k + l;

            if(cnt > best) {
                best = cnt;
                r4 = i; r3 = j; r2 = k; r1 = l;
            }
        }
    }

    if(best == -1) {
        cout << "0 0 0 0";
        return;
    }
    cout << r1 << " " << r2 << " " << r3 << " " << r4;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
