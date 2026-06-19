#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int mod = 998244353; 
bool vis[MAXN];
int n, ans, minn, sum[MAXN], a[MAXN];

int MOD(int x){
	return ((x % mod) + mod) % mod;
}

bool check(int tot, int sum, int maxx){
	if (tot < 3)
		return false;
	if (sum > 2 * maxx)
		return true;
	return false;
}

void dfs(int now, int last, int tot, int sum, int maxx){
	if (tot + last - now + 1 < minn)
		return;
	if (now == last){
		if (check(tot, sum, maxx)){
			++ans;
			ans = MOD(ans);
		}	
		return;
	}
	vis[now] = true;
	dfs(now + 1, last, tot + 1, sum + a[now], maxx);
	vis[now] = false;
	dfs(now + 1, last, tot, sum, maxx);
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i)
		sum[i] = a[i] + sum[i - 1];
	for (int i = 3; i <= n; ++i){
		minn = -1;
		for (int j = i - 2; j >= 1; --j){
			if (sum[i] - sum[j - 1] > 2 * a[i]){
				minn = i - j;
				break;
			}
		}
		if (minn == -1)
			continue;
		dfs(1, i, 1, a[i], a[i]);
	}
	cout << ans;
}
