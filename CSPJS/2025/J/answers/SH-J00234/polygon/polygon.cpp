#include <iostream>
using namespace std;
const int mod = 998244353;
long long b[5005];
long long C(long long m,long long n){
	long long ans = 1;
	ans *= (b[m] / b[m - n]),ans /= b[n];
	return ans;
}
int n,a[5005],s[5005],mx;
long long ans;
void dfs(int now,long long sum,int mx,int cnt){
	if (now == n + 1){
		if (cnt < 3) return;
		else if (!(sum > 2 * mx)) return;
		else ans++,ans %= mod;
		return;
	}
	if (2 * mx > sum + (s[n] - s[now - 1])) return;
	dfs(now + 1,sum + a[now],max(mx,a[now]),cnt + 1);
	dfs(now + 1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n,b[0] = 1;
	for (long long i = 1;i <= 5000;i++) b[i] = b[i - 1] * i % mod;
	for (int i = 1;i <= n;i++) cin >> a[i],s[i] = s[i - 1] + a[i],mx = max(mx,a[i]);
	if (mx == 1){
		for (int i = n - 1;i >= 2;i--) for (int j = i;j >= 2;j--) ans += C(i,j),ans %= mod;
		cout << ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
