#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35309 (잘 정의된 들여쓰기)
    solved by : minwoo0629a
*/

int t, n;
int cnt[100001];

void solve() {
    cin >> t;

    bool flag;
    int in, mi;
    while(t--) {
        flag = true;
        mi=-1;
        memset(cnt, 0, sizeof(cnt));
        cin >> n;

        f(i, n) {
            cin >> in;
            if(in == 1) {
                cnt[++mi] = 1;
            }
            else {
                bool fl = false;
                for(int j = mi; j>-1; j--) {
                    if(cnt[j] == in-1) {
                        fl = true;
                        cnt[j]++;
                        mi = j;
                        break;
                    }
                }
                if(!fl) {flag=false;}
            }
        }
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}