#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 111111
int t,n,a[N],cnt,dp[1111][1111][2];
map<int,int>id;
int main(){
	open("color");
	cin>>t;
	while(t--){
		cnt=0;
		id.clear();
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],id[a[i]];
		for(auto&i:id)
			i.second=++cnt;
		id[0]=-1;
		memset(dp,0x80,sizeof(dp));
		dp[0][0][0]=0,dp[0][0][1]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=cnt;j++){
				for(int k=0;k<=cnt;k++){
					dp[i][j][0]=max({dp[i][j][0],dp[i-1][j][0]+(a[i-1]==a[i])*a[i],
						(j==id[a[i-1]]?dp[i-1][k][1]+(k==id[a[i]])*a[i]:(int)-1e9)}),
					dp[i][j][1]=max({dp[i][j][1],dp[i][j][1]+(a[i-1]==a[i])*a[i],
						(j==id[a[i-1]]?dp[i-1][k][0]+(k==id[a[i]])*a[i]:(int)-1e9)});
//					cerr<<dp[i-1][j][0]<<' '<<(j==id[a[i-1]])<<' '<<dp[i-1][k][1]<<endl;
				}
//				if(dp[i][j][0]>=0||dp[i][j][1]>=0)
//					cerr<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
			}
		int ans=0;
		for(int i=0;i<=cnt;i++)
			ans=max(ans,dp[n][i][0]),ans=max(ans,dp[n][i][1]);
		cout<<ans<<endl;
	}
}

