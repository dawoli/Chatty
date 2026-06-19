#include<bits/stdc++.h>
using namespace std;

const int M=998244353;
long long a[5005],dp[5005][5005],b[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int l=3;l<=n;l++){
		for(int i=1;i<=l;i++){
			for(int j=b[l-1]-a[l];j>=0;j--){
				dp[i][j]=dp[i-1][j];
				if(a[i]<j) dp[i][j]=max(dp[i][j],dp[i][j+a[i]-1]+1)%M;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[1][i];
	}
	cout << ans;
}
