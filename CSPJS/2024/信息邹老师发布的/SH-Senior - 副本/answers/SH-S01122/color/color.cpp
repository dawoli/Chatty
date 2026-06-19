#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int T,n;
int a[200010];
int dp1[110][110][110];
int dp2[200010][17][17];
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>=1e5){
			for(int i=1;i<=n;i++) for(int j=0;j<=100;j++) for(int k=0;k<=100;k++) dp2[i][j][k]=-inf;
			dp2[1][0][a[1]]=dp2[1][a[1]][0]=0;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=10;j++){
					for(int k=0;k<=10;k++){
						if(k==j) continue;
						if(k==a[i]) dp2[i][j][k]=max(dp2[i][j][k],dp2[i-1][j][k]+k);
						else dp2[i][j][a[i]]=max(dp2[i][j][a[i]],dp2[i-1][j][k]);
						if(j==a[i]) dp2[i][j][k]=max(dp2[i][j][k],dp2[i-1][j][k]+j);
						else dp2[i][a[i]][k]=max(dp2[i][a[i]][k],dp2[i-1][j][k]);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=10;i++){
				for(int j=0;j<=10;j++){
					ans=max(ans,dp2[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++) for(int j=0;j<=100;j++) for(int k=0;k<=100;k++) dp1[i][j][k]=-inf;
			dp1[1][0][a[1]]=dp1[1][a[1]][0]=0;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=100;j++){
					for(int k=0;k<=100;k++){
						if(k==j) continue;
						if(k==a[i]) dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k]+k);
						else dp1[i][j][a[i]]=max(dp1[i][j][a[i]],dp1[i-1][j][k]);
						if(j==a[i]) dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k]+j);
						else dp1[i][a[i]][k]=max(dp1[i][a[i]][k],dp1[i-1][j][k]);
					}
				}
			}
			int ans=0;
			for(int i=0;i<=100;i++){
				for(int j=0;j<=100;j++){
					ans=max(ans,dp1[n][i][j]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
我永远喜欢珂朵莉
2024-S-T3
敲了一些部分分
加油
+50？ 
*/ 
