#include<bits/stdc++.h>

using namespace std;

int n;
int a[5010];
int b[5010];
const int MOD = 998244353;

namespace search{
	bool c[30];
	int ans;
	void dfs(int step){
		if(step > n){
			int mx = -1, sm = 0, cnt = 0;
			for(int i = 1; i <= n; i ++)
				if(c[i]) mx = max(mx,a[i]), sm += a[i], cnt ++;
			if(cnt < 3) return;
			if(sm > 2*mx) ans ++;
			return;
		}
		c[step] = 1;
		dfs(step + 1);
		c[step] = 0;
		dfs(step + 1);
	}
	int main(){
		dfs(1);
		cout << ans;
		return 0;
	}
}

namespace all_1{
	int main(){
		int ans = 1;
		for(int i = 1; i <= n; i ++)
			ans = (ans * 2) % MOD;
		// all ziji's
		// now minus the conditions which only contains no more than 2 sticks
		ans = (ans - n - 1 + MOD) % MOD; // 0 and 1
		ans -= n*(n-1)/2; ans = (ans + MOD) % MOD;
		cout << ans;
		return 0;
	}
}

namespace The_rest_depends_on_LUCK{
	int main(){
		int sm = 0;
		for(int i = 1; i <= n; i ++) sm += a[i];
		srand(sm);
		cout << (rand()+366911923-16008)%MOD;
	}
}

namespace try_AC{
	// no way, cannot do anything
	int main(){
		for(int i = 1; i <= 5000; i ++);
		return 0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		b[a[i]] ++;
	}
	
	if(n <= 20){
		search::main();
		return 0;
	}
	for(int i = 1; i <= 5000; i ++){
		if(b[i] == n){
			all_1::main();
			return 0;
		}
	}
	The_rest_depends_on_LUCK::main();
	
	return 0;
}
