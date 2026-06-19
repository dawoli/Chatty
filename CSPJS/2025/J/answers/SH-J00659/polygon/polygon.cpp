#include<bits/stdc++.h>
using namespace std;
typedef long long lint;
#define maxn 5234
#define modn 998244353
lint n, a[maxn], maxx = -1, b[25], ans;
lint mfct(lint x){
    if(x < 2) return 1;
    lint res = 1;
    for(lint i = 2; i <= x; i++){
        res *= i;
        res %= modn;
    }
    return res;
}
void dfs(lint pos, lint mxlen){
    if(pos == mxlen){
        lint maxli = -1, sumli = 0;
        for(lint i = 0; i < mxlen; i++){
            maxli = max(maxli, a[b[i]]);
            sumli += a[b[i]];
        }
        if(sumli > maxli * 2){
            ans++;
            ans %= modn;
        }
        return;
    }
    for(lint i = (pos == 0 ? 0 : b[pos-1] + 1); i < n; i++){
        b[pos] = i;
        dfs(pos + 1, mxlen);
    }
}
int main(){
    // polygen -> polygon
    // 10 : 30
    // 10 : 42 - 11 : 12 try DP, may false
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(lint i = 0; i < n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if(n == 3){
        lint othsum;
        othsum = a[0] + a[1] + a[2] - maxx;
        if(othsum > maxx){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }
    if(maxx == 1){
        cout << mfct(n) << endl;
        return 0;
    }
    for(lint i = 3; i <= n; i++){
        dfs(0, i);
    }
    cout << ans << endl;
    return 0;
}