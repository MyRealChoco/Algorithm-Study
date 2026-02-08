#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 17092 (색칠 공부)
    solved by : minwoo0629a
*/

int h, w, n;
ll re[10];
map<pair<int, int>, int> cnt;

void solve() {
    cin >> h >> w >> n;

    int x, y;
    f(i, n) {
        cin >> y >> x;
        
        f(dy, 3) {
            f(dx, 3) {
                int xt = x - dx;
                int yt = y - dy;

                if(xt < 1 || yt < 1 || xt > w-2 || yt > h-2) continue;
                cnt[{xt, yt}]++;
            }
        }
    }

    for(auto p : cnt) re[p.second]++;
    re[0] = (ll)(h-2)*(w-2) - cnt.size();

    f(i, 10) cout << re[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}