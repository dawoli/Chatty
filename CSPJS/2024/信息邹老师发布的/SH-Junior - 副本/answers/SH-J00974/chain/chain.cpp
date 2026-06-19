#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
vector<ll> a[N];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout); 
	ll t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a)); 
		ll n,k,q;
		cin>>n>>k>>q;
		for(ll i = 1;i <= n;i++){
			ll l;
			cin>>l;
			for(ll j = 1;j <= l;j++){
				ll x;
				cin>>x;
				a[i].push_back(x);
			}
		}
		while(q--){
			ll r,c;
			cin>>r>>c;
			if(r==1){
				ll sx,ans=0;
				for(ll i = 1;i <= n;i++){
					for(ll j = 0;j < a[i].size();j++){
						if(a[i][j]==1)sx=j; 
						if(a[i][j]==c){
							if(j-sx<k && j!=sx){
								ans=1;break;
							}
						}
					}
					if(ans==1)break;
				} 
				cout<<ans<<'\n'; 
			}
		}
	}
	return 0;
}

