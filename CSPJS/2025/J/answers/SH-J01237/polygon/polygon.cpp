#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e6+10,biao2=5e3+10,mod=998244353;
int a[biao],f[biao2][biao2*2][2],n,s[biao2*2];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	ll tot=2*a[n];
	f[0][0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=tot;j++) f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1])%mod;
		for(ll j=a[i];j<=tot;j++) f[i][j][1]=((f[i][j][1]+f[i-1][j-a[i]][0])%mod+f[i-1][j-a[i]][1])%mod;
	}
	
//	for(ll i=1;i<=n;i++){
//		for(ll j=0;j<=tot;j++) cout<<f[i][j][0]<<" ";cout<<'\n';
//		for(ll j=0;j<=tot;j++) cout<<f[i][j][1]<<" ";cout<<'\n';
//	}
	
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ll sum=0;
		for(ll j=1;j<=2*a[i];j++) sum=(sum+f[i][j][1])%mod;
		ll q=1;
		for(ll j=1;j<i;j++) q=q*2%mod;
//		cout<<q<<" "<<s[2*a[i]]<<'\n';
		ans=((ans+q)%mod-sum+mod)%mod;
	}
	cout<<ans;
	
	return 0;
}
