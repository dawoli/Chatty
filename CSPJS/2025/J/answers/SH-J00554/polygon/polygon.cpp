#include <bits/stdc++.h>
using namespace std;
int n,a[5010],sum,ans;
void dfs(int s,int dep,int k){
	if(dep==k){
		if(a[s]*2<sum) ++ans;
		return;
	}
	for(int i=s+1;i<=n;++i){
		sum+=a[i];
		dfs(i,dep+1,k);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int k=3;k<=n;++k){
		for(int i=1;i<=n;++i){
			sum=a[i];
			dfs(i,1,k);
		}	
	}
	cout<<ans;
}
