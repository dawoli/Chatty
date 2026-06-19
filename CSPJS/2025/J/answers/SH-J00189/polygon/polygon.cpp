#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353,N=5002;
ll n,a[N],f[N],ans,M;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	M=a[n]+2;f[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=a[i]+1;j<M;j++)
			ans=(ans+f[j])%mod;
		for(ll j=M-1;j>=0;j--){
			ll k=min(M-1,j+a[i]);
			f[k]=(f[k]+f[j])%mod;
		}
	}
	cout<<ans;
	return 0;
}
