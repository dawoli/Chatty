#include<iostream>
#include<cstdio>
#include<algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1000010;
int n, a[N], pre[N], pos[N];
ll s[N], f[N], g[N];

void solve(){
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) s[i] = i>1 && a[i-1]==a[i] ? a[i] : 0, pos[a[i]] = 0;
    rep(i, 1, n){
        s[i] += s[i-1];
        pre[i] = pos[a[i]], pos[a[i]] = i;
    }
    rep(i, 1, n){
        f[i] = f[i-1]; g[i] = 0;
        if(pre[i]){
            g[i] = f[pre[i]] + a[i];
            if(pre[i] < i-1){
                g[i] = f[pre[i]] + a[i] + s[i-1] - s[pre[i]+1];
                if(pre[pre[i]+1] && pre[pre[i]+1] < pre[i]) 
                    g[i] = max(g[i], g[pre[i]+1] + a[i] + s[i-1] - s[pre[i]+1]);
            }
        }
        f[i] = max(f[i], g[i]);
    }
    printf("%lld\n", f[n]);
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; scanf("%d", &T); while(T--) solve();
    return 0;
}

// g++ -std=c++14 -Wall -Wextra -fsanitize=undefined -Wno-unused-result -O2 color.cpp -o color && ./color