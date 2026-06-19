#include <bits/stdc++.h>
using namespace std;

	int n,k,a[5010];
	bool c[5010];
	long long ans = 0;

	void dfs(int x,int p){
		if (x >= 3){
			int mx = 0;
			long long sum = 0;
			for (int i = 1;i <= p;i++){
				if (c[i] == 1){
					if (a[i] > c[mx]){
						mx = i;
					}
					sum += a[i];
				}
			}
			if (sum > a[mx] * 2){
				ans++;
				ans %= 998244353;
			}
		}
		if (x == n || p == n || c[n] == 1){
			return;
		}
		c[p + 1] = 1;
		dfs(x + 1,p + 1);
		c[p + 1] = 0;
		dfs(x,p + 1);
	}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0,0);
	cout << ans % 998244353 - 2 << endl;
	return 0;
}
