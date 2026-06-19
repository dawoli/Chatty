//2:1 3:7 4:4 5:2 6:0,(6) 7:8
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,T;
int dp[N],num[8]={0,0,1,7,4,2,0,8};
int main(){
	//freopen("sticks.in","r",stdin);
	//freopen("sticks.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	dp[1]=-1;
	dp[6]=6;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=2;i<=n;i++){
			if(i==6||dp[i]!=0x3f3f3f3f)continue;
			for(int j=2;j<=7;j++){
				if(j>i||dp[i-j]==-1)continue;
				dp[i]=min(dp[i],10*dp[i-j]+num[j]);
			}
			if(dp[i]==0x3f3f3f3f)dp[i]==-1;
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}

