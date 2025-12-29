#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 20914 (QWERTY 자판)
    solved by : minwoo0629a
*/

string a1 = "QWERTYUIOP";
string a2 = "ASDFGHJKL";
string a3 = "ZXCVBNM";

int bfs(char a, char b) {
    if(a==b) return 0;

    int tmp;
    bool v[26] = {0, };
    queue<pair<char, int>> q;
    
    q.emplace(a, 0);
    v[a-'A'] = true;

    while(!q.empty()) {
        auto[cur, cnt] = q.front();
        q.pop();
        int nxt = cnt + 2;

        if(a1.find(cur) != string::npos) {
            tmp = a1.find(cur);

            if(tmp-1 >= 0 && !v[a1[tmp-1]-'A']) {
                v[a1[tmp-1]-'A'] = true;

                if(a1[tmp-1] == b) return nxt;
                else q.emplace(a1[tmp-1], nxt);
            }
            if(tmp+1 < 10 && !v[a1[tmp+1]-'A']) {
                v[a1[tmp+1]-'A'] = true;

                if(a1[tmp+1] == b) return nxt;
                else q.emplace(a1[tmp+1], nxt);
            }

            if(tmp-1 >= 0 && !v[a2[tmp-1]-'A']) {
                v[a2[tmp-1]-'A'] = true;
                
                if(a2[tmp-1] == b) return nxt;
                else q.emplace(a2[tmp-1], nxt);
            }
            if(tmp < 9 && !v[a2[tmp]-'A']) {
                v[a2[tmp]-'A'] = true;
                
                if(a2[tmp] == b) return nxt;
                else q.emplace(a2[tmp], nxt);
            }
        }
        else if(a2.find(cur) != string::npos) {
            tmp = a2.find(cur);
            
            if(tmp-1 >= 0 && !v[a2[tmp-1]-'A']) {
                v[a2[tmp-1]-'A'] = true;

                if(a2[tmp-1] == b) return nxt;
                else q.emplace(a2[tmp-1], nxt);
            }
            if(tmp+1 < 9 && !v[a2[tmp+1]-'A']) {
                v[a2[tmp+1]-'A'] = true;

                if(a2[tmp+1] == b) return nxt;
                else q.emplace(a2[tmp+1], nxt);
            }
            
            if(!v[a1[tmp]-'A']) {
                v[a1[tmp]-'A'] = true;
                
                if(a1[tmp] == b) return nxt;
                else q.emplace(a1[tmp], nxt);
            }
            if(!v[a1[tmp+1]-'A']) {
                v[a1[tmp+1]-'A'] = true;
                
                if(a1[tmp+1] == b) return nxt;
                else q.emplace(a1[tmp+1], nxt);
            }

            if(tmp-1 >= 0 && !v[a3[tmp-1]-'A']) {
                v[a3[tmp-1]-'A'] = true;
                
                if(a3[tmp-1] == b) return nxt;
                else q.emplace(a3[tmp-1], nxt);
            }
            if(tmp < 7 && !v[a3[tmp]-'A']) {
                v[a3[tmp]-'A'] = true;
                
                if(a3[tmp] == b) return nxt;
                else q.emplace(a3[tmp], nxt);
            }
        }
        else if(a3.find(cur) != string::npos) {
            tmp = a3.find(cur);
            
            if(tmp-1 >= 0 && !v[a3[tmp-1]-'A']) {
                v[a3[tmp-1]-'A'] = true;

                if(a3[tmp-1] == b) return nxt;
                else q.emplace(a3[tmp-1], nxt);
            }
            if(tmp+1 < 7 && !v[a3[tmp+1]-'A']) {
                v[a3[tmp+1]-'A'] = true;

                if(a3[tmp+1] == b) return nxt;
                else q.emplace(a3[tmp+1], nxt);
            }

            if(!v[a2[tmp]-'A']) {
                v[a2[tmp]-'A'] = true;
                
                if(a2[tmp] == b) return nxt;
                else q.emplace(a2[tmp], nxt);
            }
            if(!v[a2[tmp+1]-'A']) {
                v[a2[tmp+1]-'A'] = true;
                
                if(a2[tmp+1] == b) return nxt;
                else q.emplace(a2[tmp+1], nxt);
            }
        }
    }
    
    return -1;
}

void solve() {
    int n;
    string s;
    cin >> n;

    while(n--) {
        cin >> s;
        int re, l;
        re = l = s.length();
        f(i, l-1) {
            re += bfs(s[i], s[i+1]);
        }
        cout << re << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}