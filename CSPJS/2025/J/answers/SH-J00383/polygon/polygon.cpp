#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

long long b,c,d,e,n,m,ans;
long long a[5005],dp[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int k=a[i-1];
		for(int j=5002;j>=0;j--){
			int t=j+k;
			if(t>5000){
				t=5001;
			}
			dp[t]+=dp[j];
			dp[t]%=mod;
		}
		dp[k]++;
		for(int j=a[i]+1;j<=5002;j++){
			ans+=dp[j];
		}
		ans%=mod;
	}
	cout<<ans%mod;
	
	
	
	return 0;
}
