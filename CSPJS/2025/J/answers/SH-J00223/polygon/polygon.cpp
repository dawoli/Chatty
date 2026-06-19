#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++i)
#define per(i,a,b) for(int i = b;i >= a;--i)
typedef long long ll;
const ll mod = 998244353; 
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9')x = x * 10 + ch - '0',ch = getchar();
	return x * f;
}
void write(ll x){
	if(x < 0)putchar('-'),x = -x;
	write(x / 10);
	putchar(x % 10 + '0');
	return;
}
#define N 5005
ll n,a[N],res = 1,dp[N * 3],dp2[N * 3];
#undef N
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	rep(i,1,n)a[i] = read(),(res *= 2) %= mod;
	--res;
	sort(a + 1,a + n + 1); 
	dp[0] = 1;
	rep(i,1,n){
//		cout << a[i] << endl;
		per(j,1,2 * a[n]){
			if(j < a[i]){
				dp2[j] = 0;
				continue;
			}
			dp2[j] = dp[j - a[i]];
//			cout << j << " " << dp2[j] << "\n";
			dp2[j] %= mod;
		}
//		cout << endl;
		rep(j,a[i],2 * a[i])res -= dp2[j];
		rep(j,1,2 * a[n])dp[j] += dp2[j],dp[j] %= mod;
		res = (res % mod + mod) % mod;
	}
//	rep(j,1,10)cout << dp[j] << " ";
//	cout << endl;
	cout << res << endl;
	return 0;
}

