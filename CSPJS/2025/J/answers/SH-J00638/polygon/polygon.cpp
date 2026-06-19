#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,tsc;
const int mod=998244353;
void dfs(int step,int sum,int maxn){
	if(step>n){
		if(sum>2*maxn){
			ans++;
		}
		return;
	}
	dfs(step+1,sum,maxn);
	dfs(step+1,sum+a[step],max(maxn,a[step]));
}
long long mypow2(long long n){
	long long ans=1;
	while(n>30){
		n-=30;
		ans*=(1<<30);
		ans%=mod;
	}
	ans*=(1<<n);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		tsc=max(tsc,a[i]);
	}
	if(tsc==1){
		long long ans=mypow2(n);
		ans-=n;
		ans--;
		ans-=(n*(n-1)/2);
		if(ans<0)
			ans+=mod;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

