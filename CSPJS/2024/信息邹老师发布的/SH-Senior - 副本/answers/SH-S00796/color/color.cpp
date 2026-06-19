#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
const ll A=1000009;
ll n,t,a[N],b[N],cnt[A];
ll find(ll k){
	for(ll i=k-1;i>=1;i--){
		if(b[i]==b[k]){
			return a[i];
		}
	}
	return -1;
}
void solvebf(){
	ll c=0,ans=0;
	for(ll ptn=0;ptn<32768;ptn++){
		c=0;
		ll s=ptn;
		for(ll wei=14;wei>=0;wei--){
			b[wei+1]=0;
			if(s>=pow(2,wei)){
				b[wei+1]=1;
				s-=pow(2,wei);
			}
		}
		for(ll i=1;i<=n;i++){
			if(find(i)==a[i]){
				c+=a[i];
			}
		}
		ans=max(c,ans);
	}
	cout<<ans<<endl;
}
void solve(){
	for(ll i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	ll ans=0;
	for(ll i=1;i<=A;i++){
		ans+=(cnt[i]-1)*i;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(ll u=1;u<=t;u++){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=15){
			solvebf();
		}else{
			solve();
		}
	}
	return 0;
}
