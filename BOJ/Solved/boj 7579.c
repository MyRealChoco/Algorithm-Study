#include <stdio.h>
#define MAX(a,b) a>b ? a:b

/*
    problem : boj 7579 (앱)
    solved by : minwoo0629a
*/

int a[101][2];
int dp[101][10001];

void solve() {
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i][0]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i][1]);

    for(int i=1;i<=n;i++){
        for(int j=0;j<10001;j++) {
            if(a[i][1] <= j) dp[i][j] = MAX(dp[i-1][j], a[i][0] + dp[i-1][j-a[i][1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    for(int j=0; j<10001; j++) {
        if(dp[n][j] >= m) {
            printf("%d",j);
             return;
        }
    }
}

int main() {
    solve();
    return 0;
}