#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int mod=998244353;
int a[N];
long long s[N];
long long dp[N][N];
long long qmi(int nu,int idx){
	if(idx==0)return 1;
	if(idx==1)return nu;
	int mid=idx>>1;
	long long ans=1;
	if(idx%2){
		ans*=qmi(nu,mid);
		ans*=qmi(nu,mid);
		ans%=mod;
		ans*=nu;
		ans%=mod;
	}else{
		ans*=qmi(nu,mid);
		ans*=qmi(nu,mid);
		ans%=mod;
	}
	return ans;
}
long long cho(int po,int nu){
	if(nu<0)return 0;
	if(dp[po][nu])return dp[po][nu];
	if(po==1&&nu>=0)return 1;
	if(nu<a[1])return 1;
	if(po==2){
		return 2;
	}
	if(nu<a[2])return 2;
	if(s[po-1]<=nu){
		dp[po][nu]=qmi(2,po-1);
		return dp[po][nu];
	}//删多少都可以
	long long ans=1;
	for(int i=po-1;i>=1;i--){
		if(a[i]>nu)continue;
		ans+=cho(i,nu-a[i]);
		ans%=mod;
	}
	dp[po][nu]=ans;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	long long ans=0;
	for(int i=n;i>=3;i--){
		ans+=cho(i,s[i-1]-a[i]-1);
		ans%=mod;
	} 
	cout<<ans<<endl;
	return 0;
} 
