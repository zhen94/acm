#include<stdio.h>
#include<string.h>

char s[260];
int pos[260], rang[260];

int main(){
    int del;
    while (~scanf("%s%d",s, &del)){
        int len = strlen(s);
        int cnt = 0;
        int sum = 0;
        int flag = 0;
        char ts[260];
        int ed = len - del;
        int mark = 0;
        pos[0] = -1;
        rang[0] = 0;
        for (int i = 0; i < len; i++){
            if (s[i] == '0'){
                pos[++ cnt] = i;
                rang[cnt] = i - pos[cnt - 1] - 1;
                sum += rang[cnt];
                if (sum > del){
                    mark = 1;
                    sum -= rang[cnt];
                    flag = pos[cnt - 1] + 1;
                    break;
                }
            }
        }
        if (!mark){
            flag = pos[cnt] + 1;
        }
        del -= sum;
        strcpy(ts, s + flag);
        //printf("%s--\n", ts);
        if (del >= strlen(ts)){
            printf("0\n");
            continue;
        }

        int res = 0;
        while (del > 0 && res <= ed){
            //printf("%d\n", del);
            int tv = '9' + 1;
            int tp = 0;
            for (int i = res; i <= res + del; i++){
                if (ts[i] < tv){
                    tv = ts[i];
                    tp = i;
                }
            }
            del -= (tp - res);
            strcpy(ts + res, ts + tp);
            res ++;
            //printf("%s**%d**%d\n", ts, res, del);
        }
        printf("%s\n", ts);
    }
    return 0;
}
