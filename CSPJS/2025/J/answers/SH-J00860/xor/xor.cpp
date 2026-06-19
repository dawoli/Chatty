#include <iostream>
using namespace std;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int dp[500005];
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int cnt = 0;
	if(a[1] == k){
		dp[1] = 1;
	}else{
		dp[1] = 0;
		cnt++;
	}
	for(int i = 2;i <= n;i++){
		int check = 0;
		if(a[i] == k){
			dp[i] = dp[i-1] +1;
			check = 1;
			cnt = 0;
		}else{
			
			cnt++;
			if(cnt < 2){
				
			}else{
			
				int ans = a[i];
				for(int j = 2;j <=cnt;j++){
					ans = ans ^ a[i+1-j];
					//cout << ans << endl;
					if(ans == k){
					cnt = 0;
					dp[i]=dp[i-1] +1;
					j+=cnt;
					}	
				}
			}
		}
		dp[i] = max(dp[i],dp[i-1]);	

	}
	cout << dp[n];
	
	
	return 0;
}
