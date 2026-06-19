#include<bits/stdc++.h>
using namespace std;
int t,n,ans,a[200005],c[200005];
bool col[200005];
void dfs(int dep,int ret){
	if(dep==n){
		ans=max(ans,ret);
		return;
	}
	else{
		bool jud1=false,jud2=false;
		col[dep]=true;
		for(int i=dep-1;i>=0;i--){
			if(col[i]==col[dep]){
				if(a[i]==a[dep]){
					dfs(dep+1,ret+a[i]);
					jud1=true;
				}
				break;
			}
		}
		if(!jud1) dfs(dep+1,ret);
		col[dep]=false;
		for(int i=dep-1;i>=0;i--){
			if(col[i]==col[dep]){
				if(a[i]==a[dep]){
					dfs(dep+1,ret+a[i]);
					jud2=true;
				}
				break;
			}
		}
		if(!jud2) dfs(dep+1,ret);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++) cin>>a[j];
		ans=0;
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
