#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200001],bj[200001],ans;
void dfs(ll ni){
	if(ni>n){
		ll j1=-1,j2=-1;
		ll jans=0;
		for(int i=1;i<=n;i++){
			if(bj[i]==1){
				if(a[i]==j1)jans+=a[i];
				j1=a[i];
			}
			else{
				if(a[i]==j2)jans+=a[i];
				j2=a[i];
			}
		}
		ans=max(ans,jans);
		return;
	}
	bj[ni]=1;
	dfs(ni+1);
	bj[ni]=0;
	dfs(ni+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		memset(bj,0,sizeof(bj));
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
