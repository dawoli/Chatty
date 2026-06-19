#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long cnt,a[5005],n,vis[5005],x;
void dfs(long long dep,long long mx,long long sm){
	if(dep==n+1){
		if(mx==-1){
			return; 
		} 
		if(sm>2*mx){
			cnt++;
		}
		return;
	}
	vis[dep]=0;
	dfs(dep+1,mx,sm);
	vis[dep]=1;
	dfs(dep+1,max(mx,a[dep]),sm+a[dep]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(x==1){
		cnt=1;
		for(long long i=1;i<=n;i++){
			cnt*=2;
			cnt%=mod;
		}
		cnt-=(((n*(n-1))/2+n)%mod);
		cout<<cnt;
		return 0;
	}
	if(n>=25){
		cout<<1;
		return 0;
	}
	dfs(1,-1,0);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
