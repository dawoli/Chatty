#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp1[2010][2010][2],dp2[200010][15][2],s[200010],n,dmax;
signed main(){
	freopen("color.in","r",stdin); 
	freopen("color.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		memset(dp1,-0x3f,sizeof(dp1));
		memset(dp2,-0x3f,sizeof(dp2));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i]; 
		if(n>2000){
			dmax=10;
				dp2[0][0][0]=dp2[0][0][1]=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<=dmax;j++)
					for(int k=0;k<2;k++){
						dp2[i+1][s[i]][k^1]=max(dp2[i+1][s[i]][k^1],dp2[i][j][k]+((j==s[i+1])?j:0));
						dp2[i+1][j][k]=max(dp2[i+1][j][k],dp2[i][j][k]+((s[i]==s[i+1])?s[i]:0));
					}
			int ans=0;
			for(int i=0;i<=dmax;i++)
				ans=max(ans,max(dp2[n][i][1],dp2[n][i][0]));
			cout<<ans<<endl;
	//		dp(dp2);
		}
		else{
			dmax=2000;
				dp1[0][0][0]=dp1[0][0][1]=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<=dmax;j++)
					for(int k=0;k<2;k++){
						dp1[i+1][s[i]][k^1]=max(dp1[i+1][s[i]][k^1],dp1[i][j][k]+((j==s[i+1])?j:0));
						dp1[i+1][j][k]=max(dp1[i+1][j][k],dp1[i][j][k]+((s[i]==s[i+1])?s[i]:0));
					}
			int ans=0;
			for(int i=0;i<=dmax+1;i++)
				ans=max(ans,max(dp1[n][i][1],dp1[n][i][0]));
			cout<<ans<<endl;
	//		dp(dp1);
		}
	}
} 
