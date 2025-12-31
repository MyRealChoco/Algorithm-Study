#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 31784 (포닉스의 문단속)
    solved by : minwoo0629a
*/

int n, k;
string s;

void solve() {
    cin >> n >> k >> s;

    f(i, n) {        
        if(i==n-1) {
            char t = s[i] + (k%26);
            if(t > 90) t -= 26;
            cout << t;
            break;
        }

        if(s[i] == 'A') {
            cout << s[i];
        }
        else if('Z' - s[i] + 1 <= k) {
            cout << "A";
            k -= 'Z'-s[i]+1;
        } else {
            cout << s[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}