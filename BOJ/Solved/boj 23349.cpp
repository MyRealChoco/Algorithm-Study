#include <bits/stdc++.h>
#define ll long long
#define f(a, b) for(int a=0; a<(b); a++)
using namespace std;

/*
    problem : boj 23349 (졸업 사진)
    solved by : minwoo0629a
*/

int n, s, e;
string name, place;
unordered_set<string> nm;
map<string, vector<pair<int,int>>> mp;

void solve() {
    cin >> n;

    f(i, n) {
        cin >> name >> place >> s >> e;
        if (nm.count(name)) continue;
        
        nm.emplace(name);
        mp[place].emplace_back(s, e);
    }

    string re = "";
    int reCnt = -1, reS = 0, reE = 0;

    for (auto &kv : mp) {
        const string &p = kv.first;
        const auto &arr = kv.second;

        vector<int> xs;
        for (auto &it : arr) {
            xs.push_back(it.first);
            xs.push_back(it.second);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int bestCnt = 0;
        vector<pair<int,int>> segs;

        int size = xs.size();
        for (int i=0; i+1 < size; i++) {
            int l = xs[i], r = xs[i + 1];
            int cnt = 0;

            for (auto &it : arr) {
                if (it.first <= l && r <= it.second) cnt++;
            }

            if (cnt > bestCnt) {
                bestCnt = cnt;
                segs.clear();
                segs.push_back({l, r});
            } else if (cnt == bestCnt) {
                if (!segs.empty() && segs.back().second == l) segs.back().second = r;
                else segs.push_back({l, r});
            }
        }

        if (bestCnt > reCnt || (bestCnt == reCnt && (re.empty() || p < re))) {
            reCnt = bestCnt;
            re = p;
            reS = segs[0].first;
            reE = segs[0].second;
        }
    }

    cout << re << " " << reS << " " << reE << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
