#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 35297 (KSA 문자열 3)
    solved by : minwoo0629a
*/

int l;
ll re;
string x;
deque<char> v;

char target(int idx) {
    int tmp = idx%3;
    if(tmp == 1) return 'K';
    else if(tmp == 2) return 'S';
    else return 'A';
}

void solve() {
    cin >> x;
    l = x.length();
    f(i, l) v.emplace_back(x[i]);

    char t;
    for(int i=0; i<l; i++) {
        t = target(l-i);
        while(true) {
            if(v.size() > 0 && v.back() == t) break;

            if(v.size() >= 2) {
                re++; v.pop_back(); v.pop_back();
            }
            else {
                re++;
                v.emplace_front(t);
                v.emplace_front(t);
            }
        }
        v.pop_back();
    }
    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
