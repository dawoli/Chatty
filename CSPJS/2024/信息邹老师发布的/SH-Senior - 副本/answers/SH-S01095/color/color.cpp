#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll n,ans,tmp,a[N],c[N],nxt[N];
ll count_score(){
	ll scr=0;
	ll nr=-1,nb=-1;
	for(ll i=0;i<n;i++){
		if(c[i]==0){
			if(a[i]==nr) scr+=a[i];
			nr=a[i];
		}
		else{
			if(a[i]==nb) scr+=a[i];
			nb=a[i];
		}
	}
	return scr;
}
void dfs(ll loc){
	if(loc==n){
		tmp=count_score();
		ans=max(ans,tmp);
		return;
	}
	// 0->red 1->blue
	c[loc]=0; dfs(loc+1);
	c[loc]=1; dfs(loc+1);
	return;
}
void solve(){
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i];
	fill(c,c+n,0);
	ans=0;
	dfs(0);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ll T;
	cin>>T;
	for(ll i=0;i<T;i++)
		solve();
	return 0;
}

