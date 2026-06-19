#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
ll n,k,a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1,f1=1;
	for (ll i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]!=a[i-1]&&i!=1) f=0;
		if (a[i]!=0&&a[i]!=1) f1=0;
	}
	if (f==1&&k==0) {
		cout<<n;
		return 0;
	}
	if (f1==1&&k==1) {
		ll ans=0;
		for (ll i=1;i<=n;i++) {
			if (a[i]==1&&a[i-1]==0) ans++;
		}
		cout<<ans;
		return 0;
	}
	if (f1==1&&k==0) {
		ll ans1=0;
		if (a[1]==0) ans1++;
		for (ll i=1;i<=n;i++) {
			if (a[i]==0&&a[i-1]==1) ans1++;
		}
		cout<<ans1;
		return 0;
	}
	return 0;
}
