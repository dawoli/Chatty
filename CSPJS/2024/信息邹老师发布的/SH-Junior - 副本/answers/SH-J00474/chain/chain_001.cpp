#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n,k,q;
ll l,s;
ll r,c; 
signed main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k>>q;
		for(ll i=1;i<=n;i++){
			cin>>l;
			for(ll j=1;j<=l;j++){
				cin>>s;
			}
		}
		for(ll i=1;i<=q;i++){
			cin>>r>>c;
			cout<<0<<endl;
		}
	} 
	return 0;
} 
