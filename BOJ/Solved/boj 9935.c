#include <stdio.h>
#include <string.h>

/*
    problem : boj 9935 (문자열 폭발)
    solved by : minwoo0629a
*/

char stack[1000001];

int main(){
    char str[1000001];
    char bomb[37];
    int slen, blen, idx=0;

    scanf("%s %s", str, bomb);
    slen = strlen(str);
    blen = strlen(bomb);

    for(int i=0; i<slen; i++) {
        stack[idx++] = str[i];
        if(idx >= blen) {
            int temp = idx - blen, j;
            for (j = temp; j < idx; j++) if (stack[j] != bomb[j-temp]) break;
            idx -= (j == idx ? blen : 0);
        }
    }
    stack[idx] = '\0';
    puts(idx ? stack : "FRULA");
}