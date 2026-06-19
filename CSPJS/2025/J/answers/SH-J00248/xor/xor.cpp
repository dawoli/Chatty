#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 10;
ll a[N], ans[N], res = 0, n, k;
struct node{
    ll num;
}t[N << 3];
void pushup(ll p) {
    t[p].num = t[p << 1].num ^ t[(p << 1) | 1].num;
}
void build(ll p, ll l, ll r) {
    if(l == r) {
        t[p].num = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build(((p << 1) | 1), mid + 1, r);
    pushup(p);
}
void qq(ll p,ll L, ll R, ll s, ll x) {
    if(L == R) {
        if((s^t[p].num)==k) {
            ans[x] = R;
        }
        return;
    }
    ll mid = (L + R) >> 1;
    qq((p << 1), L, mid, s, x);
//  if(p == 2&& x == 1) cout << ans[x]<<endl;
    if(ans[x])return;
    qq(((p << 1) | 1), mid + 1, R, s + t[p << 1].num, x);
  //if(p == 2&& x == 1) cout << ans[x]<<endl;
}
int query(ll p, ll L, ll R, ll x) {
    if(L == R) {
        if(a[x] == k) {
            ans[x] = x;
            return 0;
        }
        return a[x];
    }
    ll mid = (L + R) >> 1;
    if(x <= mid) {
       ll c = query((p << 1), L, mid, x);
        if(ans[x]) return 0;
        qq(((p << 1) | 1), mid + 1, R, c, x);
        return c;
    } else {
        return query(((p << 1) | 1), mid + 1, R, x);
    }
}
int main() {
    freopen("stdin", "r", stdin);
   freopen("stdout", "w", stdout);
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for(ll i = 1; i <= n; i++) {
        query(1, 1, n, i);
    }
    for(ll i = 1; i <= n; i++) {
        ll t1 = i, an = 0;
        while(t1 <= n) {
            if(ans[t1] == 0) {
                t1++;
            } else {
                t1 = ans[t1] + 1;
                an++;
            }
        }
        res = max(res, an);
    }
    cout << res << endl;
    return 0;
}
