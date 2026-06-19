#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao1=1e6+10,biao2=(1<<20)+10;
ll n,k,f[biao1],s[biao1],mx[biao2];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		s[i]=s[i-1]^x;
	}
	
	for(ll i=1;i<(1<<20);i++) mx[i]=-1e18;
	ll ans=0;
	for(ll i=1;i<=n;i++){
		f[i]=max(f[i-1],mx[s[i]^k]+1);
		mx[s[i]]=max(mx[s[i]],f[i]);
		ans=max(ans,f[i]);
//		cout<<mx[0]<<" "<<s[i]<<'\n';
//		for(ll j=0;j<=3;j++){
//		if(mx[j]==-1e18) cout<<-1<<" ";
//		else cout<<mx[j]<<" ";
//		}
//		cout<<'\n';
	}
	cout<<ans;
	
	return 0;
}
