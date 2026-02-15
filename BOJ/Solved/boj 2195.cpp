#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 2195 (문자열 복사)
    solved by : minwoo0629a
*/

int re, ss, ps;
string s, p;
vector<vector<int>> c(62);

int conv(char a) {
    if(a<'A') return a - '0';
    else if(a<'a') return a - 'A' + 10;
    else return a - 'a' + 36;
}

int g(int a, int b) {
    int re = 1;
    for(int i=1; a+i<ps && b+i<ss; i++) {
        if(p[a+i] != s[b+i]) break;
        re++;
    }
    return re;
}

void solve() {
    cin >> s >> p;
    ss = s.size();
    f(i, ss) c[conv(s[i])].emplace_back(i);

    ps = p.size();
    f(i, ps) {
        int m = 0;
        for(auto &j : c[conv(p[i])]) {
            m = max(m, g(i, j));
        }
        re++;
        i += m-1;
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}