#include<bits/stdc++.h>
using namespace std;
long long _,n,a[10][100100],dp[300][300][300],mx,k;
bool o;
bool cmp(long long e,long long r){
	return e>r;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		mx=0;
		o=0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[2][i]!=0||a[3][i]!=0){
				o=1;
			}
		}
		if(o==0){
			sort(a[1]+1,a[1]+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				mx+=a[1][i];
			}
		}
		dp[0][0][0]=0;
		dp[1][0][0]=a[1][1];
		dp[0][1][0]=a[2][1];
		dp[0][0][1]=a[3][1];
		for(int l=1;l<=n;l++){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2&&i+j<=l;j++){
					k=l-i-j;
					if(k>n/2){
						continue;
					}
					if(i==0&&j==0){
						dp[i][j][k]=dp[i][j][k-1]+a[3][k];
					}
					else if(k==0&&j==0){
						dp[i][j][k]=dp[i-1][j][k]+a[1][i];
					}
					else if(i==0&&k==0){
						dp[i][j][k]=dp[i][j-1][k]+a[2][j];
					}
					else if(i==0){
						dp[i][j][k]=max(dp[i][j-1][k]+a[2][l],dp[i][j][k-1]+a[3][l]);
					}
					else if(j==0){
						dp[i][j][k]=max(dp[i-1][j][k]+a[1][l],dp[i][j][k-1]+a[3][l]);
					}
					else if(k==0){
						dp[i][j][k]=max(dp[i][j-1][k]+a[2][l],dp[i-1][j][k]+a[1][l]);
					}
					else{
						dp[i][j][k]=max(dp[i-1][j][k]+a[1][l],max(dp[i][j-1][k]+a[2][l],dp[i][j][k-1]+a[3][l]));
					}
					if(i+j+k==n){
						mx=max(mx,dp[i][j][k]);
						
					}
				}
			}
		}
		cout<<mx<<"\n";
	}
}
