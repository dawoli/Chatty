#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int INF = 1e9;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>a(n+1,vector<int>(3));
		for(int i =1; i <= n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		int m = n / 2;
		vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,INF)));
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; i++){
			for(int y = 0; y <=m;y++){
				for(int z =0; z <= m; z++){
					int k = i - y - z;
					if(k < 0|| k > m) continue;
					if(y > 0){
						dp[i][y][z] = max(dp[i][y][z],dp[i-1][y-1][z]+a[i][0]);
					}
					if(z > 0){
						dp[i][y][z] = max(dp[i][y][z],dp[i-1][y][z-1]+a[i][1]);
					}
					if(k > 0){
						dp[i][y][z] = max(dp[i][y][z],dp[i-1][y][z]+a[i][2]);
					}
				}
			}
		}
		int ans = INF;
		for(int y = 0; y <= m;y++){
			for(int z = 0;z <= m; z++){
				if(n - y - z <= m){
					ans = max(ans,dp[n][y][z]);
				}
			}					
		}
		cout<<ans<<endl;
	}
	return 0;
}
