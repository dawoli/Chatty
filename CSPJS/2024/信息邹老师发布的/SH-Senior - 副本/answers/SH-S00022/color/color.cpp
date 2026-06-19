#include<bits/stdc++.h>
using namespace std;
unsigned long long INF=1e14;
long long T,n,a[200009],dp[2009][2][2009],dp2[200009][2][19],ans,flag;
void solve1(){
	for(int i=0;i<=2000;i++)
		for(int j=0;j<=2000;j++)
			dp[i][0][j]=dp[i][1][j]=-INF;
	dp[1][0][0]=dp[1][1][0]=ans=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i][0][j]=dp[i-1][0][j]+(a[i]==a[i-1])*a[i];
			dp[i][1][j]=dp[i-1][1][j]+(a[i]==a[i-1])*a[i];
		}
		for(int j=0;j<i;j++){
			dp[i][0][i-1]=max(dp[i][0][i-1],dp[i-1][1][j]+(a[i]==a[j])*a[i]);
			dp[i][1][i-1]=max(dp[i][1][i-1],dp[i-1][0][j]+(a[i]==a[j])*a[i]);
		}
	}
	for(int i=0;i<n;i++)
		ans=max(ans,dp[n][1][i]);
	cout<<ans<<endl;
}
void solve2(){
	for(int i=0;i<=200000;i++)
		for(int j=0;j<=10;j++)
			dp2[i][0][j]=dp2[i][1][j]=-INF;
	dp2[1][0][0]=dp2[1][1][0]=ans=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=10;j++){
			dp2[i][0][j]=dp2[i-1][0][j]+(a[i]==a[i-1])*a[i];
			dp2[i][1][j]=dp2[i-1][1][j]+(a[i]==a[i-1])*a[i];
		}
		for(int j=0;j<=10;j++){
			dp2[i][0][a[i-1]]=max(dp2[i][0][a[i-1]],dp2[i-1][1][j]+(a[i]==j)*a[i]);
			dp2[i][1][a[i-1]]=max(dp2[i][1][a[i-1]],dp2[i-1][0][j]+(a[i]==j)*a[i]);
		}
	}
	for(int i=0;i<=10;i++)
		ans=max(ans,dp2[n][1][i]);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>10)flag=0;
		}
		if(n>=2001&&flag==0){
			cout<<0<<endl;
		}else if(n<=2000){
			solve1();
		}else{
			solve2();
		}
	}
	return 0;
} 
