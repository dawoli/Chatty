#include<bits/stdc++.h>
using namespace std;
int n,a[3005],b[3005];
int m;
int dfs(int k,int ans,int a1,int a2){
	if(k==m+1){
		return ans;
	}
	if(a[k]==a1&&a[k]==a2){
		return max(dfs(k+1,ans+a1,a1,a2),dfs(k+1,ans+a2,a1,a[2]));
	}
	if(a[k]==a1){
		return max(dfs(k+1,ans+a1,a1,a2),dfs(k+1,ans,a1,a[k]));
	}
	if(a[k]==a2){
		return max(dfs(k+1,ans,a[k],a2),dfs(k+1,ans+a[k],a1,a[k]));
	}
	return max(dfs(k+1,ans,a[k],a2),dfs(k+1,ans,a1,a[k]));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m;
		for(int i=1;i<=m;i++){
	    	cin>>a[i];
    	}
    	cout<<dfs(1,0,0,0)<<endl;
	}
	return 0;
} 
