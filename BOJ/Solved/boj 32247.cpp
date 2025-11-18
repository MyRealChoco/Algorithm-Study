#include <bits/stdc++.h>
#define f(a, b) for(int a=0;a<b;a++)
#define ll long long
using namespace std;

/*
    problem : boj 32247 (이상한 나라의 끈끈이주걱)
    solved by : minwoo0629a
*/

typedef struct Node{
    int c, x, y;
}Node;

int n, m;
vector<Node> v;

bool compare(Node a, Node b) {
    return a.x < b.x;
}

void solve() {
    cin >> n >> m;
    f(i, m) {
        Node tmp;
        cin >> tmp.c >> tmp.x >> tmp.y;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end(), compare);
    
    
    int x=0, y=0;
    f(i, m) {
        auto[c, nx, ny] = v[i];
        
        if(c==0) {
            if(ny >= y) y = ny+1;
            else y = max(y-(nx-x), ny+1);
        } else {
            if(ny >= y) y -= (nx-x);
            else {
                if(ny <= y-(nx-x)) {
                    cout << "adios";
                    return;
                }
                else y -= (nx-x);
            }
        }

        x = nx;
    }

    if((y-(n-x)) > 0) cout << "adios";
    else cout << "stay";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}