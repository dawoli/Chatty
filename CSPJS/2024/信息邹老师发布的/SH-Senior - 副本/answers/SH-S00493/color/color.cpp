#include<iostream>
using namespace std;
int n;
int a[200005];
long long ans=0;
long long dp[105][105][105];
long long dp2[200005][13][13];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		int flag=1;
		for(int i = 1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>10) flag=0;
		}
		if(n<=100){
			for(int i = 1;i<=n;i++){
				for(int j = 0;j<=100;j++){
					for(int k = 0;k<=100;k++){
						dp[i][j][k]=-1e18;
					} 
				}
			}
			dp[1][a[1]][0]=0,dp[1][0][a[1]]=0;
			for(int i = 2;i<=n;i++){
				for(int j = 0;j<=100;j++){
					for(int k = 0;k<=100;k++){
						dp[i][a[i]][k]=max(dp[i][a[i]][k],dp[i-1][j][k]+(a[i]==j?j:0));
						dp[i][j][a[i]]=max(dp[i][j][a[i]],dp[i-1][j][k]+(a[i]==k?k:0));
					}
				}
			}
			for(int i = 1;i<=100;i++){
				for(int j = 1;j<=100;j++){
					ans=max(ans,dp[n][i][j]);
				}
			}
			printf("%lld\n",ans);
		}else if(flag){
			for(int i = 1;i<=n;i++){
				for(int j = 0;j<=10;j++){
					for(int k = 0;k<=10;k++){
						dp2[i][j][k]=-1e18;
					} 
				}
			}
			dp2[1][a[1]][0]=0,dp2[1][0][a[1]]=0;
			for(int i = 2;i<=n;i++){
				for(int j = 0;j<=10;j++){
					for(int k = 0;k<=10;k++){
						dp2[i][a[i]][k]=max(dp2[i][a[i]][k],dp2[i-1][j][k]+(a[i]==j?j:0));
						dp2[i][j][a[i]]=max(dp2[i][j][a[i]],dp2[i-1][j][k]+(a[i]==k?k:0));
					}
				}
			}
			for(int i = 1;i<=10;i++){
				for(int j = 1;j<=10;j++){
					ans=max(ans,dp2[n][i][j]);
				}
			}
			printf("%lld\n",ans);
		}else{
			printf("0\n");
		}
	}
	return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4

3
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
100
17 18 18 19 17 19 20 20 18 19 18 19 18 19 19 19 18 17 19 17 40 40 40 37 40 39 39 39 38 39 38 40 37 40 38 40 38 39 39 40 59 60 58 60 59 58 59 58 60 57 58 60 57 60 57 60 58 60 57 60 80 80 79 80 78 77 80 79 79 80 79 79 79 77 80 77 77 80 80 78 100 100 98 97 97 99 98 99 100 99 100 98 98 99 98 98 100 100 97 98
*/
