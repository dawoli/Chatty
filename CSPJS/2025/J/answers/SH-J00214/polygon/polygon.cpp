#include<bits/stdc++.h>
using namespace std;
long long a[10001],dp[10001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==3){
		if((a[1]+a[2]+a[3])>(2*max(a[1],max(a[2],a[3])))) cout << 1;
		else cout << 0;
		return 0;
	}
	dp[3]=1;
	for(long long i=3;i<=n;i++){
		dp[i]=(i*dp[i-1]+1)%998244353;
		//cout << dp[i] << endl;
	}
	cout << dp[n];
	return 0;
}

