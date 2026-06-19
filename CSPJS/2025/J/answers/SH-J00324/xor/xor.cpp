#include <bits/stdc++.h>
#define N 500008
using namespace std;
int n,k;
int a[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int m=a[j]^a[i-1];
			if(m==k){
				dp[j]=max(dp[j],dp[i-1]+1);
			}else{
				dp[j]=max(dp[j],dp[j-1]);
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

