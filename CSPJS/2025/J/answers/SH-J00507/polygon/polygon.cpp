#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005],s[5005];
bool f[5005];
long long ans=0;
int mx=0;

void dfs(int x,int maxn,int sum,int cnt){
	if(x>n){
		if(maxn*2<sum && cnt>=3) ans++;
		ans%=mod;
		return;
	}	
	dfs(x+1,maxn,sum,cnt);
	dfs(x+1,max(maxn,a[x]),sum+a[x],cnt+1);
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(mx==1){
		long long sum=1;
		for(int i=3;i<=n;i++){
			sum=1ll;
			for(int j=0;j<i;j++) sum*=(n-j);
			for(int j=i;j>=2;j--) sum/=j;
			ans+=sum;
			ans%=mod;
		}
		cout<<ans%mod<<endl;
		return 0;
	}
	else if(n<=20){
		dfs(1,0,0,0);
		cout<<ans%mod<<endl;
		return 0;
	}
	return 0;
}
