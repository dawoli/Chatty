#include<bits/stdc++.h>
using namespace std;
int a[5001];
int ans=1;
int n;
void dfs(int sum,int mx,int d){
	if(d>n){
		return;
	}
	mx=max(mx,a[d]);
	sum=sum+a[d];
	dfs(sum,mx,d+1);
	dfs(sum,mx,d+2);
	if(sum>mx*2){
		ans++;
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,-1,0);
	cout<<ans%998%244%353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
