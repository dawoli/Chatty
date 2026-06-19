#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353,ans;
bool vis[5005],f=false;
void dfs(long long x){
	if (x == n+1){
		long long maxn=0,m=0,sum=0;
		for (int i=1;i<=n;i++){
			if (vis[i]){
				maxn = max(maxn,a[i]);
				m++;
				sum += a[i];
			}
		}
		if (m < 3) return;
		if (sum > maxn*2) ans++;
		ans%=mod;
		return;
	}
	vis[x] = true;
	dfs(x+1);
	vis[x] = false;
	dfs(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (a[i] > 1) f = true;
	}
	if (f) dfs(1);
	else {
		long long sum = 1;
		long long base=n;
		for (int i=1;i<=3;i++){
			sum *= base;
			base--;
		}
		for (int i=3;i<=n;i++){
			ans += sum;
			ans%=mod;
			sum *= base;
			base--;
		}
	}
	cout << ans%mod << endl;
	return 0;
}
