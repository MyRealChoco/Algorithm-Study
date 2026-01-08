#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16722 (결! 합!)
    solved by : minwoo0629a
*/

int n, a[3], re;
vector<tuple<int, int, int>> v(1);
vector<int> c;
bool used[1025];

int parseInt(string s) {
    if(s.compare("CIRCLE") == 0 || s.compare("YELLOW") == 0 || s.compare("GRAY") == 0) return 1;
    else if(s.compare("TRIANGLE") == 0 || s.compare("RED") == 0 || s.compare("WHITE") == 0) return 2;
    else return 3;
}

int p(int a, int b, int c) {
    return pow(2, a) + pow(2, b) + pow(2, c);
}

void bt(int bef, int idx, int cnt) {
    if(cnt == 3) {
        int cnt;
        bool tmp[3] = {0, };
        
        cnt = 0;
        f(i, 3) tmp[get<0>(v[a[i]]) - 1] = true;
        f(i, 3) if(tmp[i]) cnt++;
        if(cnt == 2) return;

        memset(tmp, 0, sizeof(bool)*3);
        cnt = 0;
        f(i, 3) tmp[get<1>(v[a[i]]) - 1] = true;
        f(i, 3) if(tmp[i]) cnt++;
        if(cnt == 2) return;

        memset(tmp, 0, sizeof(bool)*3);
        cnt = 0;
        f(i, 3) tmp[get<2>(v[a[i]]) - 1] = true;
        f(i, 3) if(tmp[i]) cnt++;
        if(cnt == 2) return;

        c.emplace_back(p(a[0], a[1], a[2]));
        return;
    }

    for(int i=bef+1; i<10; i++) {
        a[idx] = i;
        bt(i, idx+1, cnt+1);
    }
}

void solve() {
    for(int i=1; i<10; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        v.emplace_back(parseInt(a), parseInt(b), parseInt(c));
    }

    bt(-1, 0, 0);
    cin >> n;
    char in;
    bool f_g = false;
    int found=0;

    while(n--) {
        cin >> in;
        if(in == 'H') {
            int t1, t2, t3, t;
            cin >> t1 >> t2 >> t3;
            t = p(t1, t2, t3);
            
            if(used[t]) re--;
            else {
                f(i, c.size()) {
                    if(t == c[i]) {
                        re++;
                        found++;
                        used[t] = true;
                        break;
                    }
                }
                if(!used[t]) re--;
            }
        }
        else {
            if(!f_g && c.size() - found == 0) {
                re += 3;
                f_g = true;
            }
            else re--;
        }
    }
    cout << re << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}