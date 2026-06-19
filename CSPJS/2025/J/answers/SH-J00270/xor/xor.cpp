#include<bits/stdc++.h>
using namespace std;
int k=0;
int n,m;
int a[50009];
int id[260][200];
int t[260];
int main(){
	cin>>n>>m;
	a[0]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
		id[a[i]][++t[a[i]]]=i;
	}
	int dp[50009];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<=t[a[i]^m];j++){
			if(id[a[i]^m][j]<i)
			dp[i]=max(dp[i],dp[id[a[i]^m][j]]+1);
		}
	}
	if(m!=0) cout<<dp[n];
	else cout<<dp[n]-1;
	return 0;
}
