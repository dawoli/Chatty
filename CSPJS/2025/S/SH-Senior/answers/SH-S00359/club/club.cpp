#include<bits/stdc++.h>
using namespace std;
const int N=10010;
const int H=N/2;
int dp[N][N][H];
int a[N][3];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int half=n/2;
		
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=half;j++){
				for(int k=0;k<=half;k++){
					dp[i][j][k]=-1;
				}
			}
		}
		dp[0][0][0]=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=half;j++){
				for(int k=0;k<=half;k++){
					if(dp[i][j][k]==-1) continue;
					int i2=i-j-k;
					if(i2<0||i2>half) continue;
					if(j+1<=half) dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+a[i][0]);
					if(k+1<=half) dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+a[i][1]);
					if(i2+1<=half) dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i][2]);
					
				}
			}
		}
		int ans=-1;
		for(int j=0;j<=half;j++){
			for(int k=0;k<=half;k++){
				int i2=n-j-k;
				if(i2>=0&&i2<=half){
					ans=max(ans,dp[n][j][k]);
				}
			}
		}	
	cout<<ans<<endl;
		
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
