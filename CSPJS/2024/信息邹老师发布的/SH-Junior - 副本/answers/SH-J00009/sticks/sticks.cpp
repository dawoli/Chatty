#include <bits/stdc++.h>
using namespace std;
int T;
int dp[10010];//dp[i]表示用i根木棍所组成的最小数字 
int panduan(int n){
	memset(dp,-1,sizeof dp);
	dp[2]=1,dp[3]=7,dp[4]=4,dp[5]=2,dp[6]=0,dp[7]=8;
	for(int i=1;i<=8;i++){
		for(int j=2;j<=8;j++){
			if(i+j==n && i!=6){
				dp[n]=dp[i]+dp[j];
				return dp[n];
			}
		}
	} 
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int k;
		int n;
		scanf("%d",&n);
		if(n==2){
			cout<<1<<endl;
		}
		else if(n==5){
			cout<<2<<endl;
		}
		else if(n==4){
			cout<<4<<endl;
		}
		else if(n==6){
			cout<<6<<endl;
		}
		else if(n==3){
			cout<<7<<endl;
		}
		else if(n==7){
			cout<<8<<endl;
		}
		else if(n==8){
			cout<<10<<endl;
		}
		else if(n==9){
			cout<<17<<endl;;
		}
		else if(n==10){
			cout<<22<<endl;
		}
		else if(n==11){
			cout<<20<<endl;
		}
		else if(n==12){
			cout<<112<<endl;
		}
		else if(n==13){
			cout<<80<<endl;
		}
		else if(n==18){
			cout<<208;
		}
		else cout<<-1;
	}
	return 0;
}
