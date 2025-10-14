#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 1744 (수 묶기)
    solved by : minwoo0629a
*/

int n;
vector<int> v(50);

void solve() {
    int re=0, idx;
    cin >> n;
    idx = n;
    f(i,n) cin >> v[i];
    sort(v.begin(), v.begin() + n);
    
    f(i,n) {
        if(v[i] > 1){
            idx = i;
            break;
        }
    }
    for(int i=0; i<idx; i++) {
        if(i+1 < idx) {
            if(v[i+1] < 1) re += v[i]*v[i+1];
            else re += v[i] + v[i+1];
            i++;
        } else {
            re += v[i];
        }
    }
    for(int i=n-1; i>=idx; i--) {
        if(i-1 >= idx) {
            re += v[i]*v[i-1];
            i--;
        } else {
            re += v[i];
        }
    }

    cout << re;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}