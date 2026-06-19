#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll qpow(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1)res=res*a%mod;
		a=a*a%mod;
		n/=2;
	}
	return res;
}
ll inv[12345],a[12345],ans;
int n;
bool vis[12345];
ll C(int a,int b){
	ll res=1;
	for(int i=a;i>=a-b+1;i--)res=res*i%mod;
	for(int i=1;i<=b;i++)res=res*inv[i]%mod;
	return res;
}
void dfs(int k,int dep,int ch){
	if(dep>k){
		if(ch<3)return;
		ll Max=0,maxd=0,sum=0;
		for(int i=1;i<=k;i++){
			if(vis[i]==0)continue;
			if(a[i]>Max){
				Max=a[i];
				maxd=i;
			}
		}
		for(int i=1;i<=k;i++)
			if(vis[i]==1&&i!=maxd)sum+=a[i];
		if(sum>Max)ans++;
		return;
	}
	vis[dep]=1;
	dfs(k,dep+1,ch+1);
	vis[dep]=0;
	dfs(k,dep+1,ch);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	for(int i=1;i<=5000;i++)inv[i]=qpow(i,mod-2);
	cin>>n;
	bool flg=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flg=0;
	}
	if(flg==1){
		for(int i=3;i<=n;i++)ans=(ans+C(n,i))%mod;
		cout<<ans<<'\n';
	}
	dfs(n,1,0);
	cout<<ans<<'\n';
	return 0;
}

//dp[i][j]:i±ßÐÎ,Ç°j¸öÄ¾¹÷¡£
/*
n>=a1+a2+...+am.
sort
prefixSum
O(n)
MAXm

*/ 
