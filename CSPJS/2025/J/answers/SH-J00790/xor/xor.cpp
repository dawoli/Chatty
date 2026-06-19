#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int a[500010],dp[500010][2];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==1){
		if(a[0]==k)cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==2){
		if(a[0]^a[1]==k)cout<<1;
		else cout<<0;
		return 0;
	}
	if(a[0]==k){
		dp[0][0]=1;
		t++;
	}
	for(int i=1;i<n;i++){
		int m=0;int x=t;
		while(x<=i){
			for(int q=t;q<=i;q++){
			m^=a[q];
			}
		x++;
		}
		if(m==k){
			dp[i][0]=max(dp[i-1][0]++,dp[i-1][1]++);
			t=i;
		}
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
	}
	cout<<max(dp[n-1][0],dp[n-1][1]);
	return 0;
}
