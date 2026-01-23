#include <stdio.h>

/*
    problem : boj 10942 (팰린드롬?)
    solved by : minwoo0629a
*/

int dp[2001][2001];

void solve() {
    int n, m;
    scanf("%d", &n);
    int arr[n+1], s, e;
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        dp[i][i] = 1;
        if (i > 1 && arr[i] == arr[i-1]) dp[i-1][i] = 1;
    }
	
    for (int len = 2; len < n; len++)
        for (int s = 1; (e = s+len) <= n; s++)
            if (arr[s] == arr[e] && dp[s+1][e-1]) dp[s][e] = 1;
		
    scanf("%d", &m);
    while (m--){
        scanf("%d %d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}


int main(){
    solve();
    return 0;
}