#include<bits/stdc++.h>
using namespace std;

int n, k, a[500005], s[500005], ans;
int f[2][500005][2]; 

//01背包，价值为1，代价为i  前i个物品容量为j 

void dfs(int step, int sum){
	if (step > n){
		ans = max(ans, sum);
		return ;
	}
	for (int i = step; i <= n; i ++){
		if (s[i] ^ s[step-1] == k){
			dfs(i+1, sum+1);
		}
	}
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	if (n <= 10){
		dfs(1, 0);
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i ++){
		for (int j = i; j <= n; j ++){
			//取 
			if (s[j] ^ s[i-1] == k){
				f[i/2][j][1] = f[(i-1)/2][i][0] + 1;
			}else{
				f[i/2][j][1] = f[(i-1)/2][i][0];
			}
			//不取
			f[i/2][j][0] = max(f[i/2][j-1][0], max(f[(i-1)/2][j][0] , f[(i-1)/2][j][1])); 
		}
	}
//	for (int i = 1; i <= n; i ++){
//		for (int j = 1; j <= n; j ++){
//			if (j < i) cout << "0 ";
//			else cout << (s[j] ^ s[i-1]) << " ";
//		} 
//		cout << endl;
//	}
	cout << max(f[n/2][n][0], f[n/2][n][1]);
	return 0;
} 
