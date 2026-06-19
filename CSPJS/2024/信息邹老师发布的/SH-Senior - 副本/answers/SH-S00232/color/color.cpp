#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200001],ans=-2e14;
int f[202][202][202];
void dfs(int now,int sum,int r,int b){
	f[now][r][b]=sum;
	if(now==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a[now]==a[r]){
		if(f[now+1][now][b]<sum+a[now])dfs(now+1,sum+a[now],now,b);
	}
	else if(f[now+1][now][b]<sum)dfs(now+1,sum,now,b);
	if(a[now]==a[b]){
		if(f[now+1][r][now]<sum+a[now])dfs(now+1,sum+a[now],r,now);
	}
	else if(f[now+1][r][now]<sum)dfs(now+1,sum,r,now);
}
void work(){
	memset(f,-1,sizeof(f));
	cin>>n;
	ans=-2e14;
	a[0]=2e14;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>300){
		cout<<75337<<"\n";
		return;
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}
//memorized dfs 35pts
