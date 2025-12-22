#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) a>b ? a:b
#define MAX_SIZE 1001

/*
    problem : boj 9251 (LCS)
    solved by : minwoo0629a
*/

int dp[MAX_SIZE][MAX_SIZE];

char in1[MAX_SIZE];
char in2[MAX_SIZE];

void solve() {
    scanf("%s %s",in1,in2);

    for(int i=0; i<(int)strlen(in1); i++) {
        for(int j=0; j<(int)strlen(in2); j++) {
            if(in1[i]!=in2[j]) {
                dp[i+1][j+1] = MAX(dp[i][j+1], dp[i+1][j]);
            }
            else {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
        }
    }

    printf("%d\n", dp[strlen(in1)][strlen(in2)]);
}

int main() {
    solve();
    return 0;
}