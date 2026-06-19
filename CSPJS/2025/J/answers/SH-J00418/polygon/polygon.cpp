// polygon
// so tired...
// 09:58 (what? I have done the first 3 problems!)
// 10:28 solving the tasks(1~10) 40pts O(2^n * n)
// 10:40 solving the tasks(15~20) 24pts O(n);
// OK! 100 + 100 + 100 + 64 = 364 pts (?)
// emm... I think this number is ......
// umm.................................
// 11:06 Eating sugar...
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
const ll MOD = 998244353;
ll a[5009];
ll u[5009]; // usage
ll ans = 0;
void dfs(ll x) {
    if(x == n + 1) {
        ll mx = 0, all = 0;
        for(int i = 1; i <= n; i++) {
            if(!u[i]) continue;
            mx = max(mx, a[i]);
            all += a[i];
        }
        if(all > 2 * mx) ans++;
        ans %= MOD;
        return;
    }
    u[x] = true;
    dfs(x + 1);
    u[x] = false;
    dfs(x + 1);
}
ll solve1() {
    // for tasks (15~20)
    ll nn = n;
    ans = 1;
    while(n--) {
        ans *= 2;
        ans %= MOD;
    }
    n = nn;
    ans -= 1 + n + n * (n - 1) / 2;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    return ans;
}
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n<=20) {
        dfs(1);
        cout<<ans;
    } else {
        cout<<solve1();
    }
    return 0;
}
