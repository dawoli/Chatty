#include<bits/stdc++.h>
using namespace std;
#define maxn 123456
#define maxb 31
typedef long long lint;
struct node{
    lint x, y, z;
    lint g(lint i){
        if(i == 0) return x;
        if(i == 1) return y;
        if(i == 2) return z;
        return -1;
    }
} a[maxn];
lint n, ans, cnt[3], b[maxb];
bool flaga = 1, flagb = 1;
bool cmpa(node p, node q){
    return p.x > q.x;
}
bool checkb(lint x){
    return false;
}
void dfs(lint pos){
    if(cnt[0] > n/2 || cnt[1] > n/2 || cnt[2] > n/2){
        return;
    }
    if(pos == n){
        lint res = 0;
        for(lint i = 0; i < n; i++){
            res += a[i].g(b[i]);
        }
        ans = max(ans, res);
    }
    for(lint i = 0; i < 3; i++){
        b[pos] = i;
        cnt[i]++;
        dfs(pos + 1);
        cnt[i]--;
    }
}
void solve(){
    flaga = 1; flagb = 1; ans = 0;
    cin >> n;
    for(lint i = 0; i < n; i++){
        cin >> a[i].x >> a[i].y >> a[i].z;
        if(a[i].y != 0) flaga = 0;
        if(a[i].z != 0) flaga = 0; flagb = 0;
    }
    if(flaga){
        sort(a, a + n, cmpa);
        for(lint i = 0; i < n / 2; i++){
            ans += a[i].x;
        }
        cout << ans << '\n';
        return;
    }
    if(flagb && n > 15){
        lint l = 0, r = (lint)1e10, mid, res = -1;
        while(l <= r){
            mid = (l + r) / 2;
            if(checkb(mid)){
                res = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        cout << res << '\n';
        return;
    }
    cnt[0] = 0; cnt[1] = 0; cnt[2] = 0;
    dfs(0);
    cout << ans << '\n';
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint t; cin >> t; while(t--){
        solve();
    }
    return 0;
}