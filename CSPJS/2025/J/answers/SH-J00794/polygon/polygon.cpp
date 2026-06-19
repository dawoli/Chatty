#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll N=5009;
ll n,a[N],f[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(ll i=1;i<N;i++) f[i]=0;
	ll mul2=1,ans=0;
	for(ll i=1;i<=n;i++){
		if(i>=3){
			ll sum=0;
			for(ll j=0;j<=a[i];j++) sum=(sum+f[j])%MOD;
			ans+=(mul2-sum);
			ans%=MOD;
		}
		for(ll j=N-1;j>=a[i];j--) f[j]=(f[j]+f[j-a[i]])%MOD;
		mul2=mul2*2%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
