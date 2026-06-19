#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const int M=2e3+5;
int _;
int n;
int a[N];
int dp[N][M],maxn[N][N],maxx[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=n;i++){
			maxx[i]=0;
			for(int j=0;j<=n;j++){
				dp[i][j]=0;
				maxn[i][j]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				if(j==i-1){
					if(maxn[i-1][a[i]]!=-1)	dp[i][j]=max(dp[i][j],maxn[i-1][a[i]]+a[i]);
					dp[i][j]=max(dp[i][j],maxx[i-1]);
				}
				else{
					dp[i][j]=dp[i-1][j];
					if(a[i]==a[i-1])	dp[i][j]+=a[i];
				}
			}
			for(int j=0;j<i;j++){
				maxx[i]=max(maxx[i],dp[i][j]);
				maxn[i][a[j]]=max(maxn[i][a[j]],dp[i][j]);
			}
		}
		cout<<maxx[n]<<endl;
	}
	return 0;
} 
