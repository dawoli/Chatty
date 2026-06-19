#include<bits/stdc++.h>
using namespace std;
int n;
const int mod=998244353;
int a[5009];
int dp[5009][5009];
int d[5009][5009];
int mm=5001;
void md(int &x){
	x%=mod;
}
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		dp[i][a[i]]+=1;
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=mm;j++){
			if(j>a[i]){
				dp[i][j]+=(dp[i-1][j-a[i]]+dp[i-1][j]);
				md(dp[i][j]);
			}
			else{
				dp[i][j]+=dp[i-1][j];
			}
		}
		for(int j=(mm-a[i]+1);j<=mm;j++){
			dp[i][mm+1]+=dp[i-1][j];
			md(dp[i][mm+1]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=(mm+1);j>=1;j--){
			d[i][j]=d[i][j+1]+dp[i][j];
			md(d[i][j]);
		}
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=d[i-1][a[i]+1];
		md(ans);
	}
	cout<<ans;
	return 0;
}
