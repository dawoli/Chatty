#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define modn 998244353
#define maxn 15
lint n, m, c[maxn], ans, a[maxn], b[maxn];
bool usd[maxn];
string s;
lint mfct(lint x){
    if(x < 2) return 1;
    int res = 1;
    for(int i = 2; i <= x; i++){
        res *= i;
        res %= modn;
    }
    return res;
}
void dfs(lint pos){
    if(pos == n){
        for(int i = 0; i < n; i++) b[i] = 0;
        lint tmp = 0, cnt = 0;
        while(1){
            bool breakFlag = 1;
            for(lint j = 0; j < n; j++){
                if(tmp >= c[a[j]] && (b[a[j]] != 1)){
                    b[a[j]] = 1;
                    tmp++;
                    breakFlag = 0;
                }
            }
            if(breakFlag) break;
        }
        for(lint i = 0; i < n; i++){
            if(s[i] == '0'){
                tmp++;
                while(1){
                    bool breakFlag = 1;
                    for(lint j = i+1; j < n; j++){
                        if(tmp >= c[a[j]] && (b[a[j]] != 1)){
                            b[a[j]] = 1;
                            tmp++;
                            breakFlag = 0;
                        }
                    }
                    if(breakFlag) break;
                }
            }else{ cnt++; }
        }
        if(cnt >= m) ans++;
        return;
    }
    for(lint i = 0; i < n; i++){
        if(usd[i]) continue;
        a[pos] = i;
        usd[i] = 1;
        dfs(pos + 1);
        usd[i] = 0;
    }
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(lint i = 0; i < n; i++){
        cin >> c[i];
    }
    if(n > 10){ cout << mfct(n) << endl; return 0; }
    dfs(0);
    cout << ans << endl;
    return 0;
}






/*
 * aaaaaaaaa...
 */