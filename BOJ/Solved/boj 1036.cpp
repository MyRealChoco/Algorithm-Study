#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1036 (36진수)
    solved by : minwoo0629a
*/

#define MX 60

int n, k;
ll form[36][MX], re[MX];

int c_idx(char c) {
    if(c < 'A') return c - '0';
    else return c - 'A' + 10;
}
char c_char(int a) {
    if(a < 10) return '0' + a;
    else return 'A' + (a-10);
}

void carry(ll a[]) {
    f(i, MX-1) {
        if(a[i] >= 36) {
            a[i+1] += a[i] / 36;
            a[i] %= 36;
        }
    }
}

struct cmp {
    bool operator()(const int a, const int b) {
        for(int i=MX-1; i>-1; i--) {
            if(form[a][i] != form[b][i]) return form[a][i] < form[b][i];
        }
        return a < b;
    }
};

void solve() {
    cin >> n;

    string s;
    int len, cur;
    f(i, n) {
        cin >> s;
        len = s.length();
        f(j, len) {
            cur = c_idx(s[len-1-j]);
            re[j] += cur;
            form[cur][j] += 35 - cur;
        }
    }

    f(i, 36) carry(form[i]);
    carry(re);

    priority_queue<int, vector<int>, cmp> pq;
    f(i, 36) pq.emplace(i);

    cin >> k;
    while(k--) {
        auto idx = pq.top();
        pq.pop();

        f(i, MX) re[i] += form[idx][i];
        carry(re);
    }

    int st = MX-1;
    while(st > 0 && re[st] == 0) st--;
    for(int i=st; i>-1; i--) cout << c_char(re[i]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}