#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b)for(ll i=(a);i<=(b);i++)
#define rrep(i, a, b) for(ll i=(a);i>=(b);i--)
const ll N=1e5+9;
ll n, cnt[N], maxa, maxcnt;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    rep(i, 1, n){
        ll a;cin >> a;
        cnt[a]++;
        maxa=max(maxa, a);
    }
    rep(i, 1, maxa){
        maxcnt=max(maxcnt, cnt[i]);
    }
    cout << maxcnt << endl;
    return 0;
}