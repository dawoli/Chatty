#include<bits/stdc++.h>
using namespace std;
#define int long long
//ten year's OI all in vain , no long long see forefathers
int T , n , a[2005] , dp[2005][2005];
/*
1
8
3 5 2 5 1 2 1 4
 */
signed main(){
	freopen("color1.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	scanf("%d" , &T);
	for(int I = 0 ; I < T ; I++){
		scanf("%d" , &n);
		memset(dp , -0x3f , sizeof(dp));
		int maxn = 0;
		dp[0][0] = 0;
		dp[2002][0] = dp[0][2002] = 0; // dp[i][2002] & dp[2002][i]
		if(n >= 2001) return 0; //114514
		for(int i = 0 ; i < n ; i++) cin >> a[i];
		for(int i = 0 ; i < n ; i++){
			for(int j = 2000 ; j >= 0 ; j--){
				if(j == a[i]) dp[j][j] = max(max(dp[j][2002] , dp[2002][j]) , dp[j][j] + j);
				else{
					dp[a[i]][j] = max(dp[a[i]][j] + a[i] , dp[2002][j]);
					dp[j][a[i]] = max(dp[j][a[i]] + a[i] , dp[j][2002]);
				}
			}
			for(int j = 2000 ; j >= 0 ; j--){
				dp[2002][j] = max(dp[2002][j] , dp[a[i]][j]);
				dp[j][2002] = max(dp[j][2002] , dp[j][a[i]]);
				dp[a[i]][2002] = max(dp[a[i]][2002] , dp[a[i]][j]);
				dp[2002][a[i]] = max(dp[2002][a[i]] , dp[j][a[i]]);
				maxn = max(maxn , max(max(dp[2002][j] , dp[2002][a[i]]) , max(dp[a[i]][2002] , dp[j][2002])));
			}

		}
		
		cout << maxn << "\n";
	} 
	
}
