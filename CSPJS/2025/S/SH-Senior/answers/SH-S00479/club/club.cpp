#include<bits/stdc++.h>
using namespace std;
#define N 1005
int t,n;
int a[N][4];
int dp[N][N/2+1][N/2+1];
//man[1][n]存的是1有n人时，2的人数。man[2][n]是2有n人时，1的人数，man[] 

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dp[1][1][1]=0;
		for(int i=1;i<=n;i++){//人数 
			for(int j=n/2+1;j>=1;j--){//1部门有j-1人 
				for(int h=n/2+1;h>=1;h--){//2部门有h-1人 
					if(j-1>i||h-1>i){
						continue;
					}
					if(j+h-2>i){
						continue;
					}
					if(i-j-h+2>n/2){
						continue;
					}
					dp[i][j][h]=max(dp[i-1][j-1][h]+a[i][1],max(dp[i-1][j][h-1]+a[i][2],dp[i-1][j][h]+a[i][3]));
				}
			}
		}

		int mx=-11;
		for(int j=1;j<=n/2;j++){
			for(int h=1;h<=n/2;h++){
				if(n-j-h>n/2){
					continue;
				}
				mx=max(mx,dp[n][j][h]);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
} 
