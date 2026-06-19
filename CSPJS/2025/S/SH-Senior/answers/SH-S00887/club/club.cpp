#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t){
		cin>>n;
		int a[100010][5],dp[100010][5]={0},dp1[100010][5]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp1[i][j]=max(dp1[i][j],a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i-1][j],dp1[i-1][j]+a[i][j]);	
			}
		}
		int max1=0;
		for(int i=1;i<=3;i++){
			max1+=dp[n][i];
		}
		cout<<max1<<endl;
	}
	return 0;
}
