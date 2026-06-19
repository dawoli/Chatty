#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod=998244353;

int n,m;
string s;

int c[505];

ll dp[1<<18][18];

ll ans;

int main(){
	ios::sync_with_stdio(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=0;i<n;++i) cin>>c[i];
	
	dp[0][0]=1;
	
	for(int i=0;i<(1<<n);++i){
		int cnt=0;
		for(int j=0;j<n;++j){
			if(i&(1<<j)) ++cnt;
		}
		
		for(int j=0;j<=cnt;++j){
			dp[i][j]%=mod;
			
			for(int k=0;k<n;++k){
				if(i&(1<<k)) continue;
				int ne=(i|(1<<k));
				
				if(s[cnt]=='0') dp[ne][j+1]+=dp[i][j];
				else{
					if(j<c[k]) dp[ne][j]+=dp[i][j];
					else dp[ne][j+1]+=dp[i][j];
				}
			}
		}
	}
	
	for(int j=0;j<=n-m;++j) ans+=dp[(1<<n)-1][j];
	
	cout<<ans%mod<<endl;
	
	return 0;
}
