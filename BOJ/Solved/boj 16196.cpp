#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 16196 (중국 신분증 번호)
    solved by : minwoo0629a
*/

string in, p, b, o;
int n;
vector<int> v;

bool isPValid() {
    int prov = stoi(p);
    for(auto &i : v) {
        if(i == prov) return true;
    }
    return false;
}

bool isCodeValid() {
    int birth = stoi(b);
    int y = birth / 10000;
    int m = (birth/100) % 100;
    int d = birth % 100;
    int order = stoi(o);
    
    if(y < 1900 || y > 2011 || m<1 || m>12 || order == 0) return false;

    bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); //윤년
    int daysInMonth[] = {0, 31, (leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d < 1 || d > daysInMonth[m]) return false;

    return true;
}

char getCheckSum() {
    int s=0, x;
    f(i, 17) {
        s = (s + (in[i]-'0')*(1<<(17-i))) % 11;
    }
    x = (12-s)%11;
    return (x>9 ? 'X' : '0'+x);
}

void solve() {
    cin >> in >> n;
    v.resize(n);
    f(i, n) {
        cin >> v[i];
    }

    p = in.substr(0, 6);
    b = in.substr(6, 8);
    o = in.substr(14, 3);
    
    if(isPValid() && isCodeValid() && in[17] == getCheckSum()) {
        cout << (stoi(o)%2 == 0 ? "F" : "M");
    } else cout << "I";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}