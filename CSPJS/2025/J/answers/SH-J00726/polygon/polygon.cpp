#include<bits/stdc++.h> 
using namespace std;
vector<int> c[5010];
bool vis[5010]; 
int n, a[5010], mem[5010][5010], maxa, maxs;//棍子数 长度和 
int mod = 998244353;
void solve() {
	long long ans = 0;
	c[0].emplace_back(1);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == i)
				c[i].emplace_back(c[i-1][j-1]);
			else if(j == 0)
				c[i].emplace_back(c[i-1][j]);
			else c[i].emplace_back((0LL + c[i-1][j] + c[i-1][j-1])%mod); 
		}
	}
	for(int i = 3; i <= n; i++){
		ans+=c[n][i]; ans%=mod;
	}cout << ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
//	freopen("polygon.in","r",stdin); 
//	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxa = max(maxa, a[i]);
	}
	if(maxa == 1){
		solve(); return 0;
	}
	
	memset(mem, -1, sizeof(mem));
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) { 
			for(int k = j; k <= n; k++) {
				int sum = a[i] + a[j] + a[k];
				maxs = max(maxs, sum);
				if(max(a[i], max(a[j], a[k])) * 2 < sum) mem[3][sum]++;
			}
		}
	}
	int ans;
	for(int i = 3; i <= maxs; i++) {
		if(mem[3][i] != -1) ans += mem[3][i];
	}
	cout << ans;
	return 0;
}
