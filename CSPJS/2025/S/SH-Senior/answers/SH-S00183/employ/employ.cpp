#include<bits/stdc++.h>
const int mod=998244353;
bool can[20];
int dp[19][262150][19];
int n,m;
int lim[20];
int ppcnt(int x){
	int res=0;
	for(int o=0;o<n;o++){
		if((1<<o)&x)res++; 
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c; std::cin>>c;
		can[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		std::cin>>lim[i];
	}
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<(1<<n);j++){
			if(ppcnt(j)!=i) continue;
			for(int x=0;x<=i;x++){
				for(int o=1;o<=n;o++){
					int mask=(1<<(o-1));
					if(mask&j){
						if(can[i]==1 and x>0 and lim[o]>i-1-(x-1)){
							dp[i][j][x]+=dp[i-1][j-mask][x-1];
					//		dp[i][j][x]%=mod;
						}
						if(can[i]==0 or lim[o]<=i-1-x){
							dp[i][j][x]+=dp[i-1][j-mask][x];
					//		dp[i][j][x]%=mod;
						}
						
					}
				}
			}
	//		std::cout<<i<<" "<<j<<" "<<dp[i][j][1]<<"\n";
 		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		ans+=dp[n][(1<<n)-1][i];
	}
	std::cout<<ans%mod;
}

