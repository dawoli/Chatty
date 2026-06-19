#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll n,t=0,r[N],die[N];
void solve2(){
	ll cnt=0,cntt=0;
	for(ll i=1;i<=n;i++){
		if(r[i]==1){
			cnt++;
		}else{
			cntt++;
		}
	}
	cout<<n-min(cnt,cntt)<<endl;
}
void solve(){
	sort(r+1,r+1+n);
	ll l=0;
	if(r[1]==r[n]){
		cout<<n<<endl;
	}else{
		for(ll i=1;i<=n;i++){
			for(ll j=max(1ll,l);j<i;j++){
				if(die[j]==0){
					if(r[i]>r[j]){
						die[j]=1;
						l=j+1;
					}
					break;
				}
				if(r[i]==r[j]){
					break;
				}
			}
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			if(die[i]==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
}
void solvezj(){
	solve();
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>r[i];
		t=max(t,r[i]);
	}
	if(t<=2){
		solve2();
	}else if(n<=10000){
		solve();
	}else{
		solvezj();
	}
	return 0;
}
