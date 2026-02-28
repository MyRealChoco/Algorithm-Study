#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 21773 (가희와 프로세스 1)
    solved by : minwoo0629a
*/

struct pro{
    int a, b, c;
    pro(int x, int y, int z) {
        a=x; b=y; c=z;
    }
};
struct compare {
    bool operator()(const pro a, const pro b) {
        if(a.c != b.c) return a.c < b.c;
        else return a.a > b.a;
    }
};

int t, n;
priority_queue<pro, vector<pro>, compare> pq;

void solve() {
    cin >> t >> n;

    int a, b, c;
    f(i, n) {
        cin >> a >> b >> c;
        pq.emplace(pro(a, b, c));
    }

    while(t--) {
        auto p = pq.top();
        pq.pop();
        cout << p.a << '\n';
        
        p.b = p.b-1;
        if(p.b != 0) {
            p.c -= 1;
            pq.emplace(p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}