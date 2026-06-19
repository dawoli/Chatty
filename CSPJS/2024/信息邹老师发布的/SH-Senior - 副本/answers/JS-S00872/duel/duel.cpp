#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
const int N = 100010;
int n, a[N], cnt[N], sum, ans;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]), cnt[a[i]]++;
    rep(i, 1, 100000){
        ans += min(sum, cnt[i]), sum = max(0, sum - cnt[i]);
        sum += cnt[i];
    }
    printf("%d\n", n - ans);
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -fsanitize=undefined -Wno-unused-result -O2 duel.cpp -o duel && ./duel