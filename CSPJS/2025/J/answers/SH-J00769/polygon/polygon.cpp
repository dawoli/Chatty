#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int pre[5009][5009];
int sum[5009];
int a[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	pre[1][0]=2;
	for(int i=1;i<=a[1];i++)
		pre[1][i]=1;
	for(int i=2;i<n;i++){
		for(int j=0;j<=min(sum[i],a[n])+1;j++)
			pre[i][j]=(pre[i-1][j]+pre[i-1][max(0,j-a[i])])%mod;
	}
	int ans=0;
	for(int i=3;i<=n;i++)
		ans=(ans+pre[i-1][a[i]+1])%mod;
	cout<<ans;
	return 0;
}
//rp++
//100+100+60+100=360 (maybe?)
