#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],dp[5005][5005][2],maxn,ans;
long long qsm(long long b){
	int mi=1;
	for(int i=1;i<=b;i++){
		mi*=2;
		mi%=998244353;
	}
	return mi;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	maxn=a[n];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxn;j++){
			dp[i][j][1]=dp[i-1][j][1];
			if(a[i]<=j)dp[i][j][1]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxn;j++){
			dp[i][j][2]=dp[i-1][j][2];
			if(j>a[i]){
				dp[i][j][2]+=dp[i-1][j-a[i]][2]+dp[i-1][j-a[i]][1];
				dp[i][j][2]%=998244353;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=(long long)(qsm(i-1))-dp[i-1][a[i]][2]-i;
		ans%=998244353;
	}
	printf("%lld",(ans+998244353)%998244353);
	return 0;
}
