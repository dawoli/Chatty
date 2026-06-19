#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define int long long
#define N 5555
const int m=5000;
const int mod=998244353;
int n,a[N],dp[N],ans;
signed main(){
	open("polygon");
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=m+1;j++)
			ans+=dp[j],ans%=mod;
		for(int j=m+1;j>m-a[i];--j)
			dp[m+1]+=dp[j],dp[m+1]%=mod;
		for(int j=m-a[i];j>=0;--j)
			dp[j+a[i]]+=dp[j],dp[j+a[i]]%=mod;
	}
	cout<<ans<<endl;
}
