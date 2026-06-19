#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
const int mod = 998244353;
// expected: 50pts
int n,a[N],ans = 0;
vector <int> edgs[N];

void dfs(int u,int maxn,int sum) {
	if(sum > 2*maxn)
		ans++;
	ans %= mod;
	for(auto v : edgs[u]) {
		dfs(v,max(maxn,a[v]),sum+a[v]);
	}
	return;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			edgs[i].push_back(j);
	for(int i = 1;i <= n;i++)
		dfs(i,a[i],a[i]);
	cout << ans%mod << "\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

