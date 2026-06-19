#include<iostream>
using namespace std;
const int N=1e3+10;
int T,n,a[N],maxn;
int dp[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//if(a[i]==a[i-1])dp[i][i-1]=a[i];
		}
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<i-1;j++){
				for(int k=j+1;k<i;k++){
					dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+(a[k-1]==a[k+1]?a[k-1]:0));
				}
			}
		}
		cout<<dp[n][1]<<endl;
		*/
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)dp[i]=max(dp[i],dp[j]);
			dp[i]+=dp[i-1];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
