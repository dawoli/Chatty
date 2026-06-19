#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
long long a[5005];
long long chs[5005];
long long ans;
void dfs(int x,int k){
	if(x==n+1){
		if(k<2)return;
		long long sum=0,maxc=0;
		for(int i=1;i<=k;i++){
			maxc=max(maxc,chs[i]);
			sum+=chs[i];
		}
		if(sum>maxc*2)ans++;
		ans=ans%Mod;
		return;
	}
	dfs(x+1,k);
	chs[k+1]=a[x];
	dfs(x+1,k+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		long long sum=0,maxa=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			maxa=max(maxa,a[i]);
		}
		if(sum>maxa*2)cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans%Mod;
	return 0;
}
