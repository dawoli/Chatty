#include<iostream>
#include<string.h>
#define unin unsigned int
using namespace std;

unin n, k;
unin a[600000] = {0}, suma[600000] = {0};
int dp[600000] = {0};
bool o[300] = {0}, p[300] = {0};

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		suma[i] = suma[i - 1] ^ a[i];
	}
	if(k <= 255){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == k){
				ans++;
				memset(o, 0, sizeof(o));
				continue;
			}
			o[0] = 1;
			memset(p, 0, sizeof(p));
			for(unin j = 0; j <= 255; j++){
				if(o[j]) p[j ^ a[i]] = 1;
			}
			for(int j = 0; j <= 255; j++){
				o[j] = p[j];
			}
			if(o[k]){
				ans++;
				memset(o, 0, sizeof(o));
				continue;
			}
		}
		cout << ans;
	}else{
		int lasta = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == k){
				dp[i] = dp[i - 1] + 1;
				lasta = i;
				continue;
			}
			for(int j = lasta; j < i; j++){
				if((suma[i] ^ suma[j]) == k){
					dp[i] = dp[i - 1] + 1;
					lasta = i;
					break; 
				}
			}
			dp[i] = max(dp[i], dp[i - 1]);
		}
		cout << dp[n];
	}
	
	return 0;
}
