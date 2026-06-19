#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500007];
int xors[500007];
int dp[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool fzo = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] !=0 && a[i]!=1) fzo = false;
	} 
	if(fzo){
		if(k == 1){
			int ans = 0;
			for(int i = 1;i<= n;i++)
				if(a[i] == 1) ans ++;
			cout << ans;	
		} 
		if(k == 0){
			int ans = 0;
			for(int i = 1;i<= n;i++){
				if(a[i] == 0) ans ++;
				if(a[i] == 1){
					int oneg = 0;
					while(i<=n && a[i] == 1){
						oneg ++;
						i++;
					}
					i--;
					ans += oneg/2;
				}
			}
			cout << ans;	
		}
		return 0;
	}
	
	xors[1] = a[1];
	for(int i = 2;i<=n;i++) xors[i] = (xors[i-1]^a[i]);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= i;j++){
			if((xors[j-1]^xors[i]) == k) dp[i] = max(dp[i],dp[j-1] + 1);
			dp[i] = max(dp[i],dp[j]);
		}
		ans = max(ans,dp[i]);
	}
	cout << ans;
	
	return 0;
}
