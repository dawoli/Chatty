#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=2e5+10;
ll n;
ll a[N],f[N],sum[N];
inline void solve2(){
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	ll ans=0;
	for(ll S=0;S<(1<<n);S++){
		ll last1=0,last0=0,tmp=0;
		for(ll i=1;i<=n;i++){
			if(S&(1<<(i-1))){
				tmp+=(a[i]==a[last1])*a[i];
				last1=i;
			}
			else{
				tmp+=(a[i]==a[last0])*a[i];
				last0=i;
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}
inline void solve(){
	cin>>n;
	if(n<=15){
		solve2();
		return;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)
			continue;
		sum[i]=sum[i-1]+(a[i]==a[i-1]?a[i]:0); 
	}
	memset(f,0,sizeof(f));
	for(ll i=2;i<=n;i++){
		for(ll j=0;j<i-1;j++)
			f[j]+=(a[i-1]==a[i])*a[i];
		for(ll j=0;j<i-1;j++)
			f[i-1]=max(f[i-1],f[j]+(a[j]==a[i])*a[i]);
	}
	ll ans=0;
	for(ll i=0;i<=n;i++)
		ans=max(ans,f[i]);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	ll T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
