#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
problem : boj 24891 (단어 마방진)
solved by : minwoo0629a
*/

int l, n;
bool visited[20];
vector<string> v;

bool bt(vector<string> sel) {
    if(sel.size() == l) {
        f(i, l) cout << sel[i] << "\n";
        return true;
    }

    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        bool flag = false;

        for(int j=0; j<sel.size(); j++) {
            if(sel[j][sel.size()] != v[i][j]) {
                flag = true;
                break;
            }
        }
        
        if(flag) continue;
        
        sel.push_back(v[i]);
        visited[i] = true;
        if(bt(sel)) return true;
        sel.pop_back();
        visited[i] = false;
    }
    return false;
}

void solve() {
    cin >> l >> n;
    f(i, n) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    vector<string> tmp;
    if(!bt(tmp)) cout << "NONE";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}