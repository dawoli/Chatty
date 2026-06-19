#include<bits/stdc++.h>
using namespace std;

int a[100005][3]={0};
int dp[201][201][201]={0};//shetuan0,shetuan2,people now all
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t=0;
	cin>>t;
	while(t>0){
		t--;
		int n=0;
		cin>>n;
		int x=0,y=0,z=0;
		int mxsum=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					dp[i][j][k]=0;
				}
			}
		}
	
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			a[i][0]=x;
			a[i][1]=y;
			a[i][2]=z;
			mxsum+=max(x,max(y,z));
		}
		if(n>201){//stole12-20
			cout<<mxsum<<endl;
			continue;
		}
		//now n<=200,use dp;
		dp[1][1][0]=a[1][0];dp[1][0][1]=a[1][1];dp[1][0][0]=a[1][2];
		for(int i=2;i<=n;i++){//peopel
			for(int j=0;j<=min(n/2,i);j++){//0
				for(int k=0;k<=min(n/2,i-j);k++){//1
				if(j>=1){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
				}
				if(k>=1){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
				}
				if(i>j+k){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
				}
			//		dp[i][j][k]=max(max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]),max(dp[i-1][j][k-1]+a[i][1],dp[i-1][j][k]+a[i][2]));
			//		cout<<"ijk:"<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			for(int j=n/2-i;j<=n/2;j++){
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
