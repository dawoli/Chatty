#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
ll n;
ll a[200005];
ll vis[200005];
int cnt;
void bfsolve(int step){
	if(step>n){
		ll r=0,b=0,ans=0;
		for(ll i=1;i<=n;i++){
			if(vis[i]==1){
				if(a[b]==a[i]) ans+=a[i];
				b=i;
			}
			else{
				if(a[r]==a[i]) ans+=a[i];
				r=i;
			}
		}
		cnt=max(cnt,ans);
		return;
	}
	vis[step]=1;
	bfsolve(step+1);
	vis[step]=0;
	bfsolve(step+1);
	return;
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		cnt=0;
		bfsolve(1);
		cout<<cnt<<endl;
	}
} 
