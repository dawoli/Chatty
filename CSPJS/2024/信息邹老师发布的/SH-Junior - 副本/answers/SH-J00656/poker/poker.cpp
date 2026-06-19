#include <bits/stdc++.h>
using namespace std;
int n, cnt;
char s[19];
bool a[59];
int trans(char* s) {
    int ret = 0;
    if(s[0] == 'C')
        ret += 13;
    else if(s[0] == 'H')
        ret += 26;
    else if(s[0] == 'S')
        ret += 39;
    if(s[1] >= '2' && s[1] <= '9')
        ret += (s[1] - '1');
    else if(s[1] == 'T')
        ret += 9;
    else if(s[1] == 'J')
        ret += 10;
    else if(s[1] == 'Q')
        ret += 11;
    else if(s[1] == 'K')
        ret += 12;
    return ret;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        a[trans(s)] = true;
    }
    for(int i = 0; i < 52; i++) {
        if(!a[i])
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}