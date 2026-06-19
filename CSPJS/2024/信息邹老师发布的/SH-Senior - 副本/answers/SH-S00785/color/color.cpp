#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[200001]={};
int v[200001]={};
int c[200001]={};
int num=0;
int ans=0;
int dfs(int dep){
	if(dep>n){
		num=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(v[i]==v[j]){
					if(a[i]==a[j]){
						num+=a[i];						
					}
					break;
				}
			}
		}
		ans=max(num,ans);
		return 0;
	}
	v[dep]=1;
	dfs(dep+1);
	v[dep]=2;
	dfs(dep+1);
	v[dep]=0;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		ans=0;
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
