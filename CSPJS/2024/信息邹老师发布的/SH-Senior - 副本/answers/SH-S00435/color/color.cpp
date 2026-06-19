#include<bits/stdc++.h>

using namespace std;
int t; 
int a[200007];
int n;
int c[200007];
long long ans;
long long maxans=-1;
void dfs(int idx){
	if(idx==n+1){
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(c[i]==c[j]){
					if(a[i]==a[j]){
						ans=ans+a[i];
					}
					break;
				}
			} 
		}
		maxans=max(maxans,ans);
		ans=0;
		return;
	}
	dfs(idx+1);
	c[idx]=1;
	dfs(idx+1);
	c[idx]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		maxans=0;
		ans=0;
		dfs(1);
		cout<<maxans<<endl;
	}
	return 0;
}
