#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int x[N];
bool f[N];
ll T,ans,n;
void solve(){
	ll cnt=0;
	for(int i=2;i<=n;i++){
		int j=i-1;
		while(j>0&&f[j]!=f[i]) j--;
		if(j==0) continue;
		if(x[i]==x[j]) cnt+=x[i];
	} 
	//cout<<cnt<<endl;
	ans=max(cnt,ans);
}
void dfs(int id){
	if(id==n+1){
		//for(int i=1;i<=n;i++) cout<<f[i]<<" ";
		solve();
		return;
	}
	dfs(id+1);
	f[id]=1;
	dfs(id+1);
	f[id]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>x[i];
		dfs(1);
		cout<<ans<<endl;
	} 
	return 0;
}
