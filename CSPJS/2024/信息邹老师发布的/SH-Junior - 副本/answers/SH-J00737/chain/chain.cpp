#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll T,n,k,q;
vector<ll> S[N];
void solve(){
	cin>>n>>k>>q;
	for(ll i=1,l,v;i<=n;i++){
		cin>>l;
		for(ll j=1;j<=l;j++)
			cin>>v,S[i].push_back(v);
	}
	for(ll i=1,r,c;i<=q;i++){
		cin>>r>>c;
		if(r==1){
			for(ll j=1;j<=n;j++)
				for(ll l=0;l<S[j].size();l++) if(S[j][l]==1)
					for(ll m=l+1;m<S[j].size()&&m<l+k;m++)
						if(S[j][m]==c) goto flag;
			cout<<0<<endl;
			continue;
			flag: cout<<1<<endl;
		}else cout<<0<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}
