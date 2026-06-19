#include <bits/stdc++.h>
using namespace std;
/*
quan'pai'lie
    prev_permutation()
    next_permutation()
*/
const int N = 510, Q = 998244353;
int n, m;
int c[N], s[N];

bool judge(){
    int sum = m;
    for(int i = 1; i <= n; i++){
        if(s[i] >= c[i]){
            sum--;
        }
    }

    if(sum >= m) return true;
    return false;
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        char c;
        scanf("%c", &c);
        s[i] = c-'0';
        s[i] += s[i-1];
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &c[i]);
    }

    int sum = 0;
    do{
        if(judge()){
            sum ++;
        }
    }while(next_permutation(c+1, c+1+n));

    printf("%d\n", sum % Q);

    return 0;
}
