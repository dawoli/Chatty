#include<bits/stdc++.h>
using namespace std;
long long t,n;
int a[100005][5],dp[100005][5];
struct node{
	int a,b,c;
}f[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				dp[i][j]=0;
				f[i].a=f[i].b=f[i].c=0;
			}
		}
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			if(dp[i-1][2]+a[i][1]>dp[i][1]&&dp[i-1][3]+a[i][1]<=dp[i-1][2]+a[i][1]&&!(dp[i-1][1]+a[i][1]>dp[i-1][2]+a[i][1]&&f[i-1].a<n/2)){
				f[i].b++;
				dp[i][1]=dp[i-1][2]+a[i][1];
			}
			else if(dp[i-1][3]+a[i][1]>dp[i][1]&&!(dp[i-1][1]+a[i][1]>dp[i-1][2]+a[i][1]&&f[i-1].a<n/2)){
				f[i].c++;
				dp[i][1]=dp[i-1][3]+a[i][1];
			}
			else if(dp[i-1][1]+a[i][1]>dp[i][1]&&f[i-1].a<n/2){
				f[i].a++;
				dp[i][1]=dp[i-1][1]+a[i][1];
			}
			
			if(dp[i-1][1]+a[i][2]>dp[i][2]&&dp[i-1][3]+a[i][2]<=dp[i-1][1]+a[i][2]&&!(dp[i-1][2]+a[i][2]>dp[i-1][1]+a[i][2]&&f[i-1].b<n/2)){
				f[i].a++;
				dp[i][2]=dp[i-1][1]+a[i][2];
			}
			else if(dp[i-1][3]+a[i][2]>dp[i][2]&&!(dp[i-1][2]+a[i][2]>dp[i-1][1]+a[i][2]&&f[i-1].b<n/2)){
				f[i].c++;
				dp[i][2]=dp[i-1][3]+a[i][2];
			}
			else if(dp[i-1][2]+a[i][2]>dp[i][2]&&f[i-1].b<n/2){
				f[i].b++;
				dp[i][2]=dp[i-1][2]+a[i][2];
			}
			
			if(dp[i-1][2]+a[i][3]>dp[i][3]&&dp[i-1][1]+a[i][3]<=dp[i-1][2]+a[i][3]&&!(dp[i-1][3]+a[i][3]>dp[i-1][2]+a[i][3]&&f[i-1].c<n/2)){
				f[i].b++;
				dp[i][3]=dp[i-1][2]+a[i][3];
			}
			else if(dp[i-1][1]+a[i][3]>dp[i][3]&&!(dp[i-1][3]+a[i][3]>dp[i-1][2]+a[i][3]&&f[i-1].c<n/2)){
				f[i].a++;
				dp[i][3]=dp[i-1][1]+a[i][3];
			}
			else if(dp[i-1][3]+a[i][3]>dp[i][3]&&f[i-1].c<n/2){
				f[i].c++;
				dp[i][3]=dp[i-1][3]+a[i][3];
			}
		}
		cout<<max(max(dp[n][1],dp[n][2]),dp[n][3])<<"\n";
	}
	return 0;
}
