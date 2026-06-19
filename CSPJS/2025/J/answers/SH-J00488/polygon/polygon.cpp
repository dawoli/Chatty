#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5050;
const ll mod=998244353;
ll n,a[maxn],A[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;bool f=1;
	for (ll i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]!=a[i-1]&&i!=1) {
			f=0;
		}
	}
	if (f==1) {
		A[1]=n;
		A[2]=n*(n-1)/2;
		ll ans=0;
		for (ll i=3;i<=n;i++) {
			A[i]=A[i-1]*(n-i+1)/i;
			ans+=A[i];
		}
		cout<<ans%mod;
	}
	return 0;
}
