#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5009];
bool ok[5009] = {0};
int cnt = 0;
bool cmp(int x1,int x2){
    return x1 > x2;
}
bool cando(){
    int tot = 0;
    int tot2 = 0;
    bool flag = 1;
    int maxn = 0;
    for(int i = 1;i <= n;i++){
        if(ok[i]){
            tot++;
            tot2 += a[i];
            if(flag){
                maxn = a[i];
                flag = 0;
            }
        }
    }
    if(tot >= 3 && tot2 > maxn * 2){
        return 1;
    }
    return 0;
}
void dfs(int x){
    //cout << x << endl;
    if(x == n+1){
        if(cando()){
            cnt += 1;
            cnt = cnt % 998244353;
        }
        return;
    }
    ok[x] = 1;
    dfs(x+1);
    ok[x] = 0;
    dfs(x+1);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    dfs(1);
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
