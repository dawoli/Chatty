#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int li[5010];
bool vis[5010];
const int mod = 998244353;
ll cnt = 0;
int n;
void dfs(int deep, int h, int l){
	for (int i = l+1; i <= n; i++){
		vis[i] = true;
		if (deep == h){
			ll sum = 0; int maxn = 0;
			for (int i = 1; i <= n; i++){
				if (vis[i]){
					sum += li[i];
					maxn = max(maxn, li[i]);
				}
			}
			if (sum > 2 * maxn){
				cnt = (cnt + 1) % mod;
			}
		} else {
			dfs(deep + 1, h, i);
		}
		vis[i] = false;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	int maxx = 0;
	for (int i = 1; i <= n; i++){
		cin >> li[i];
		maxx = li[i];
	} 
	if (maxx == 1){
		int jc[5010];
		jc[1] = 1;
		for(int i = 2; i <= n; i++){
			jc[i] = jc[i-1] * i;
		} 
		ll summ = 0;
		for (int m = 3; m <= n-1; m++){
			ll result = (jc[n] % mod) / (jc[n-m] * jc[m] % mod);
			cout << result << endl;
			summ = (result + summ) % mod;
		}
		cout << summ + 1 << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(li+1, li+1+n);
	for (int d = 3; d <= n; d++){
		dfs(1, d, 0);
	}
	cout << cnt << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
