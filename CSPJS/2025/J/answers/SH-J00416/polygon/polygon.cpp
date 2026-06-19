//60
#include <bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005][5005];
int maxn[20005];
int ans;
long long c[5005];
map <vector<int>,int> mp; 
const long long mod = 998244353;
bool check(vector<int>& v) {
//	printf("check() called with v:\n{");
//	for(int i=0;i<v.size();++i) {
//		printf("%d%c",v[i],",}"[i==v.size()-1]);
//	}
//	printf("\n");
	if(v.size() < 3) {
//		printf("size not ok: %d\n",v.size());
		return false;
	}
	int sum = 0,maxn = 0;
	for(int& k : v) {
		sum += k;
		maxn = max(maxn,k);
	}
//	if(sum >= 2*maxn+1) {
//		printf("OK!\n");
//	}
//	else {
//		printf("sum too small:%d vs %d.\n",sum,maxn);
//	}
	return sum >= 2*maxn+1;
}
void dfs(int i,vector<int> v) {
	if(i==n) {
		if(check(v)) ++ans;
		return;
	}
	dfs(i+1,v);
	v.push_back(a[i+1]);
	dfs(i+1,v);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
//n=5000;
//for(int i=1;i<=n;++i) a[i] = 1;
	if(n <= 20) {
		dfs(0,{});
		cout << ans << endl;
	}
	else {
		long long ans = 0;
		for(int i=3;i<=n;++i) {
			
			//c[i]
			c[i] = 1;
			for(int k=1;k<=i;++k) {
				c[i] = (c[i] * (n-k+1) / k) % mod;
			}
			ans = (ans+c[i]) % mod;
		}
		cout << ans << endl;
	} 
}
