#include <stdio.h>

/*
problem : boj 2759 (팬케이크 뒤집기)
solved by : minwoo0629a
*/

int stack[60];
int top, cnt;

void flips(int a[], int k) {
    for(int i=0; i<=k/2; i++) {
        int tmp = a[i];
        a[i] = a[k-i];
        a[k-i] = tmp;
    }
}

void sort(int a[], int n) {
    if(n>1) {
        int m = 0;
        for(int i=0; i<n; i++) {
            if(a[i] > a[m]) m = i;
        }
        if(m != n-1) {
            if(m != 0) {
                cnt++;
                stack[++top] = m+1;
                flips(a, m);
            }
            cnt++;
            stack[++top] = n;
            flips(a, n-1);
        }
        sort(a, n-1);
    }
}

void solve() {
    int t;
    scanf("%d", &t);

    while(t--) {
        cnt = 0;
        top = -1;
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        sort(arr, n);

        printf("%d ", cnt);
        for(int i=0; i<=top; i++) printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}