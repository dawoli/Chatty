#include <bits/stdc++.h>
using namespace std;
int t,n,a[20],vis[20],ans,cnt;
void dfs(int x){
	if(x==0){
		cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=i-1;j>=1;--j){
				if(vis[j]==vis[i]){
					if(a[i]==a[j]){
						cnt+=a[i];
					}
				}
			}
		}
		ans=max(ans,cnt);
		return;
	}
	vis[x]=0;
	dfs(x-1);
	vis[x]=1;
	dfs(x-1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;++_){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		dfs(n);
		cout<<ans<<endl;
	}
	return 0;
}
