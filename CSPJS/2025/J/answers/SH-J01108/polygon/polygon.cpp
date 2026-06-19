#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
int n, a[5005], sum[5005], maxn[3005][3005], ans;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			maxn[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			for (int l = i; l <= j; l++){
				maxn[i][j] = max(maxn[i][j], a[l]);
			}
		}
	}
	if(n <= 3){
		if(n == 3){
			if(a[1] + a[2] + a[3] > max(a[1], max(a[2], a[3])) * 2){
				cout << 1 % mod;
			}
			else	cout << 0 % mod;
		}
		else cout << 0 % mod;
	}
	else{
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				if(j - i + 1 <= 2)	continue;
				if(sum[j] - sum[i - 1] > 2 * maxn[i][j] && j - i + 1 >= 3){
					ans = (ans + 1) % mod;
				}
				for (int x = i + 1; x < j; x++){
					if(maxn[i][j] != a[x])
						if(sum[j] - sum[i - 1] - a[x] > 2 * maxn[i][j])	ans = (ans + 1) % mod;
					else{
						int mx = -1;
						for (int y = i; y <= j; y++){
							if(y != x){
								mx = max(mx, a[y]);
							}
						}
						if(sum[j] - sum[i - 1] - a[x] > 2 * mx)	ans = (ans + 1) % mod;
					}
				} 
			}
		}
		cout << ans % mod;
	}
	return 0; 
} 
