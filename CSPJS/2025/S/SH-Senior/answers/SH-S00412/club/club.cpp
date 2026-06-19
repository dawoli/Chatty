// 14:45 Start coding.
// 15:05 End coding & find a mistake
// 15:15 Solve this mistake
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100009],b[100009],c[100009];
vector<ll> x,y,z;
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld" ,&n);
        ll ans=0;
        for(int i=1;i<=n;i++) {
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
            ans += max({a[i],b[i],c[i]});
            if(max({a[i],b[i],c[i]}) == a[i]) x.push_back(a[i]-max(b[i],c[i]));
            else if(max({a[i],b[i],c[i]}) == b[i]) y.push_back(b[i] - max(a[i],c[i]));
            else z.push_back(c[i]-max(a[i],b[i]));
        }
        if(x.size()>n/2) {
            sort(x.begin(),x.end());
            for(int i=0;i<x.size()-(n/2);i++) {
                ans -= x[i];
            }
        } else if(y.size()>n/2) {
            sort(y.begin(),y.end());
            for(int i=0;i<y.size()-(n/2);i++) {
                ans -= y[i];
            }
        } else if(z.size()>n/2){
            sort(z.begin(),z.end());
            for(int i=0;i<z.size()-(n/2);i++) {
                ans -= z[i];
            }
        }
        printf("%lld\n",ans);
        x.clear();
        y.clear();
        z.clear();
    }
    return 0;
}
