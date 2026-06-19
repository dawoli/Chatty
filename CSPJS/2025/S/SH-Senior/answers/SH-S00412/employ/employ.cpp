// buxing! baoli!
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string q;
ll a[509],b[509];
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i] = i;
    }
    sort(a+1,a+n+1);
    ll ans=0;
    do {
        ll v = 0, p = 0;
        for(int i=1;i<=n;i++) {
            if(a[b[i]] <= v) v++;
            else if(q[i-1] == '0') v++;
            else p++;
        }
        if(p>=m) ans++;
    }while(next_permutation(b+1,b+n+1));
    cout<<ans;
    return 0;
}
