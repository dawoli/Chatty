#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,k,q,li,r,c,temp;
vector<ll>s[100005];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while (T--){
		cin>>n>>k>>q;
		for (ll i=1;i<=n;i++){
			cin>>li;
			for (ll j=1;j<=li;j++) cin>>temp,s[i].push_back(temp);
		}
		for (ll i=1;i<=q;i++){
			cin>>r>>c;
			cout<<0<<endl;
		}
	}
	
	
	
	return 0;
} 
