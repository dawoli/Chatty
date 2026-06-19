#include<bits/stdc++.h>
using namespace std;
int n,m,c[509],vis[509];
string s;
long long ans;
void dfs(int k,int cnt,int rvcnt){
	if(k==n+1){
		if(cnt>=m){
			ans=(ans+1)%998244353;
		}	
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(s[k-1]=='0' or c[i]<=rvcnt){
			vis[i]=1;
			dfs(k+1,cnt,rvcnt+1);
			vis[i]=0;
		}
		else{
			vis[i]=1;
			dfs(k+1,cnt+1,rvcnt);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
