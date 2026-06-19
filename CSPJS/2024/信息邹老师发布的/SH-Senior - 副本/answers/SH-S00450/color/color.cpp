#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll t,a[N],c[N];
bool st[N];
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		ll n,ans=0;
		cin>>n;
		for(ll i=1; i<=n; ++i) cin>>a[i];
		for(ll i=0; i<1<<n; ++i) {
			for(ll j=0; j<n; ++j) st[j+1]=(i>>j&1);
			memset(c,0,sizeof(c));
			ll lst1=0,lst0=0,res=0;
			for(ll j=1; j<=n; ++j) {
				if(st[j]) {
					if(a[lst1]==a[j]) c[j]=a[j];
					lst1=j;
				} else {
					if(a[lst0]==a[j]) c[j]=a[j];
					lst0=j;
				}
				res+=c[j];
			}
			ans=max(ans,res);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
