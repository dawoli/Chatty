#include<bits/stdc++.h>
using namespace std;
//滚动数组 
int T;
#define MA 100005
int a[MA],n;
#define ll long long
#define SZD 2005
ll ans=0;
ll dp[3][SZD+10][2];//
int ma;
int xian; 
void csh(){
	for(int i=0;i<=1;i++)
	for(int j=0;j<=SZD;j++)
	for(int k=0;k<=1;k++) dp[i][j][k]=-1000012345;
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	for(int h8=1;h8<=T;h8++){
		//xian=min(ma,SZD);
		cin>>n;
		ma=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			if(a[i]>ma) ma=a[i];
		}
		a[0]=-10086;
		ans=0;
		//第一个数蓝色 
		csh();
	    
		dp[0][0][1]=0;
		dp[0][0][0]=0;
		for(int k=1;k<=n;k++){
			int ty=k%2;
			for(int b=0;b<=1;b++){
				//第k位填写b
			//第k-1位填写1-b
			    for(int w=0;w<=SZD;w++){
			    	dp[ty][a[k-1]][b]=max(dp[ty][a[k-1]][b],dp[1-ty][w][1-b]);
				}
				dp[ty][a[k-1]][b]=max(dp[ty][a[k-1]][b],dp[1-ty][a[k]][1-b]+a[k]);
			    /*for(int w=0;w<=min(ma,SZD);w++){
			    	if(w!=a[k]) dp[ty][a[k-1]][b]=max(dp[ty][a[k-1]][b],dp[1-ty][w][1-b]);
			    	else{
			    		dp[ty][a[k-1]][b]=max(dp[ty][a[k-1]][b],dp[1-ty][a[k]][1-b]+a[k]);
					}
				}*/
			//第k-1位填写b
			    if(a[k]==a[k-1]){
				    for(int w=0;w<=SZD;w++) dp[ty][w][b]=max(dp[ty][w][b],dp[1-ty][w][b]+a[k]);
		     	} 
			    else{
				    for(int w=0;w<=SZD;w++) dp[ty][w][b]=max(dp[ty][w][b],dp[1-ty][w][b]);
			    }
			}
		}
		/*for(int wei=0;wei<=1;wei++)
		for(int w=0;w<=SZD;w++){
			for(int b=0;b<=1;b++){
				if(dp[wei][w][b]>=0) cout<<wei<<" "<<w<<" "<<b<<"|"<<dp[wei][w][b]<<"\n";
			}
		}*/
		int wei=n%2;
		for(int w=0;w<=SZD;w++){
			for(int b=0;b<=1;b++){
				ans=max(ans,dp[wei][w][b]);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
/*
100 
17 18 18 19 17 19 20 20 18 19 18 19 18 19 19 19 18 17 19 17 40 40 40 37 40 39 39 39 38 39 38 40 37 40 38 40 38 39 39 40 59 60 58 60 59 58 59 58 60 57 58 60 57 60 57 60 58 60 57 60 80 80 79 80 78 77 80 79 79 80 79 79 79 77 80 77 77 80 80 78 100 100 98 97 97 99 98 99 100 99 100 98 98 99 98 98 100 100 97 98
*/
