#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,a[5101];
long long ans,c[5101];
bool flag=true;
void cccc(){
	long long cnt=1,ccc=1;
	c[n]=1;
	c[0]=1;
	for(int i=1;i<=n/2;i++){
		cnt=(cnt*(n-i+1))%mod;
		ccc=ccc*i%mod;
		c[i]=cnt/ccc%mod;
	}
}
long long cc(int k){
	if(k>n/2)k=n-k;
	return c[k];
}
long long pf(){
	cccc();
	for(int i=3;i<=n;i++){
		ans=(ans+cc(i))%mod;
	}
	return ans;
}
void dfs(int mx,int pick,int step,int sum){
	if(step>n)return ;
	if(step==n&&pick>=3&&sum>2*mx){
		ans++;
	}
	dfs(max(mx,a[step+1]),pick+1,step+1,sum+a[step+1]);
	dfs(mx,pick,step+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(flag==true){
		ans=pf();
		cout<<ans;
		return 0;
	}
	dfs(a[1],1,1,a[1]);
	dfs(0,0,1,0);
	cout<<ans%mod;
	return 0;
}
