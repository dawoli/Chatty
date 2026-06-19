#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
const ll M=998244353;
int a[5009],f[5009][5009],p[5009];
ll n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	p[0]=1;
	for(ll i=1;i<5009;i++)p[i]=1ll*p[i-1]*2%M;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=*max_element(a+1,a+n+1)+1;j++){
			if(j>a[i])f[i][j]=(1ll*f[i][j]+f[i-1][j-a[i]])%M;
			else f[i][j]=(1ll*f[i][j]+p[i-1])%M;
			f[i][j]=(1ll*f[i][j]+f[i-1][j])%M;
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)ans=(1ll*ans+f[i-1][a[i]+1])%M;
	cout<<ans<<endl;
	return 0;
}


