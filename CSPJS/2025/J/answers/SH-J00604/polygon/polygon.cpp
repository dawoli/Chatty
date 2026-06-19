#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int vis[5005];
void dfs(int next){
	if(next==n+1){
		int bian=0;
		for(int i=1;i<=n;i++){
			if(vis[i])bian++;
		}
		int mx=0,sum=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				sum+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(sum>mx*2 && bian>=3){
			ans++;
		}
		return;
	}
	vis[next]=1;
	dfs(next+1);
	vis[next]=0;
	dfs(next+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
