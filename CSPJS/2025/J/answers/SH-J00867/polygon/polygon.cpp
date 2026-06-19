#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis[1000005],n,m,a[1000005],ans=0;
void dfs(int sum,int mx,int cnt,int u){
	if(u==n+1&&cnt>=3){
		if(sum>2*mx){
			ans++;
			ans%=998244353;
			return;
		}
	}
	if(u==n+1){
		return;
	}
	vis[u]=1;
	dfs(sum+a[u],max(mx,a[u]),cnt+1,u+1);
	vis[u]=0;
	dfs(sum,mx,cnt,u+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,1);
	cout<<ans;
	return 0;
} 
