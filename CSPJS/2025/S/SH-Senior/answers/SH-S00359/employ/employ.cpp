#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=510;
int n,m;
int c[N];
int dp[N][N];
string s;

int popcount(int x){
	int c=0;
	while(x){
		c+=x&1;
		x>>=1;
	}
	return c;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	
	for(int mask=0;mask<(1<<n);mask++){
		int day=popcount(mask);
		for(int j=0;j<=n;j++){
			if(dp[mask][j]==0) continue;
			for(int i=0;i<n;i++){
				if(mask&(1<<i)) continue;
				int new_mask=mask|(1<<i);
				if(j>=c[i]){
					int new_j=j+1;
					if(new_j<=n){
						dp[new_mask][new_j]=(dp[new_mask][new_j]+dp[mask][j])%mod;
					}else{
						char dif=s[day];
						if(dif=='1'){
							dp[new_mask][j]=(dp[new_mask][j]+dp[mask][j]%mod);
						}else{
							int new_j=j+1;
							if(new_j<=n){
								dp[new_mask][new_j]=(dp[new_mask][new_j]+dp[mask][j])%mod;
							}
						}
					}
				}
			}
		}
		
	}
	long long ans=0;
	for(int mask=0;mask<(1<<n);mask++){
		for(int j=0;j<=n;j++){
			if(dp[mask][j]&&(n-j)>=m){
				ans=(ans+dp[mask][j])%mod;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
