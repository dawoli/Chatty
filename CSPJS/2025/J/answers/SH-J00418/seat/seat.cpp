// seat
// number:100pts
// How about seat?
// Oh no, I forgot the freopen.
// I have to write it.
// true."sea.tin"
// Linux can't type Chinese, QwQ
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll qwq[109];
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++) cin>>qwq[i];
    ll p = 1;
    for(int i=2;i<=m*n;i++) if(qwq[i] > qwq[1]) p++;
    ll c = (p-1)/n + 1;
    ll r = 0;
    if(c%2) {
        r = p%n;
        if(r == 0) r = n;
    } else {
        r = p%n;
        if(r == 0) r = n;
        r = n + 1 - r;
    }
    cout<<c<<" "<<r;
    return 0;
}
