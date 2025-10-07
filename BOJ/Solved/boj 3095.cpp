#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<b; a++)
using namespace std;

/*
    problem : boj 3095 (플러스의 개수)
    solved by : minwoo0629a
*/

int n,cnt;
char maps[2000][2001];
vector<pair<int,int>> v;

void find() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i+1<n && j+1<n && maps[i][j-1] == '1' && maps[i][j] == '1'&& maps[i][j+1] == '1') {
                if(maps[i-1][j] == '1' && maps[i+1][j] == '1') v.push_back(make_pair(j,i));
            }
        }
    }
}
bool crossCheck(int x, int y, int size) {
    for(int i=1; i<=size; i++) {
        if(y-i<0 || y+i>=n || x-i<0 || x+i>=n) return false;
        if(maps[y][x-i] != '1' || maps[y][x+i] != '1'|| maps[y-i][x] != '1' || maps[y+i][x] != '1') {
            return false;
        }
    }
    return true;
}
bool elseCheck(int x,int y,int size) {
    if(y-size<0 || y+size>=n || x-size<0 || x+size>=n) return false;
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            if(maps[y-size+i][x-size+j]!='0' || maps[y-size+i][x+1+j]!='0' || maps[y+1+i][x-size+j]!='0' ||  maps[y+1+i][x+1+j]!='0') {
                return false;
            }
        }
    }
    return true;
}

void l_find(int x, int y) {
    int size = 1;
    while(true) {
        if(crossCheck(x,y,size) && elseCheck(x,y,size)) {
            cnt++;
            size++;
        }
        else break;  
    }
}

void solve() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> maps[i];
    }

    find();
    int size = v.size();
    for(int i=0;i<size;i++) {
        l_find(v.back().first, v.back().second);
        v.pop_back();
    }
    printf("%d",cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}