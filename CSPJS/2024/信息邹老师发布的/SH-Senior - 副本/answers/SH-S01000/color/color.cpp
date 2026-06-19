#include<bits/stdc++.h>
using namespace std;
int t,n,sum,m;
int a[200005],c[1000005];
void dfs(int i,int r,int b,int ans){
	if(i<=n){
		if(a[i]==r||r==0){
			c[a[i]]--;
			dfs(i+1,a[i],b,ans+a[i]*(r==a[i]));
			c[a[i]]++;
			return ;
		}
		if(a[i]==b||b==0){
			c[a[i]]--;
			dfs(i+1,r,a[i],ans+a[i]*(b==a[i])); 
			c[a[i]]++;
			return ;
		}
		if(c[r]==0){
			c[a[i]]--;
			dfs(i+1,a[i],b,ans);
			c[a[i]]++;
			return ;
		}
		if(c[b]==0){
			c[a[i]]--;
			dfs(i+1,r,a[i],ans);
			c[a[i]]++;
			return ;
		}
		c[a[i]]--; 
		dfs(i+1,a[i],b,ans);
		dfs(i+1,r,a[i],ans);
		c[a[i]]++;
	}else if(i>n){
		sum=max(sum,ans);
	}
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			c[a[i]]++;
			m=max(m,a[i]);
		}
		dfs(1,0,0,0);
		cout<<sum<<endl;
		sum=0;
		for(int i=1;i<=m;i++){
			c[m]=0;
		}
	}
	return 0;
} 
