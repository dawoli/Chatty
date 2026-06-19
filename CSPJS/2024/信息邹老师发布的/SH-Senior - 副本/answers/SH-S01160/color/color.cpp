#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll biao=1e5+10;
ll ans,n;
ll a[biao],col[biao];

void dfs(ll node){
	if(node==n+1){
		ll tmp=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i-1;j>=1;j--){
				if(col[j]==col[i]){
					if(a[i]==a[j]) tmp+=a[i];
					break;
				}
			}
		}
		
		ans=max(ans,tmp);
		return;
	}
	
	col[node]=1;
	dfs(node+1);
	
	col[node]=2;
	dfs(node+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	ll t;
	cin>>t;
	
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i];
		
		ans=0;
		dfs(1);
		
		cout<<ans<<endl;
	}
	
	return 0;
}
