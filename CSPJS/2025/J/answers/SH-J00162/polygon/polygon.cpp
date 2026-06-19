#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod=998244353;
int n;
int a[5009],dp[509][50009],xx;
void solve1(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
		cnt+=a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			if(j>=a[i])
				dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-a[i]]%mod)%mod;
			else
				dp[i][j]=dp[i-1][j]%mod;
		}
	}
	for(int i=3;i<=n;i++){
		int x=a[i];
		for(int j=x+1;j<=cnt;j++){
			ans+=dp[i-1][j];
			ans%=mod;
		}
	}
	cout<<ans;
}
void solve2(){
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=0;i<(1<<n);i++){
		vector<int> v;
		for(int j=0;j<n;j++){
			if((i>>j)&1)
				v.push_back(a[j+1]);
		}
		int cnt=0,maxn=0;
		for(auto p:v){
			cnt+=p;
			maxn=max(maxn,p);
		}
		if(cnt>2*maxn)
			ans++;
		ans%=mod;
	}
	cout<<ans;
}
void solve3(){
	//2^n-n-n(n-1)/2-1;
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=2*ans%mod;
	ans-=n;
	ans-=n*(n-1)/2;
	ans--;
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xx=max(xx,a[i]);
	}
	if(xx<=1)
		solve3();
	else if(n>=20&&n<=5000)
		solve1();
	else if(n<=20)
		solve2();
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
