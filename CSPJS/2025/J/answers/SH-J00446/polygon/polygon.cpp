#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int a[5005];
ll f[5005];
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int n; scanf("%d" , &n);
	for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
	sort(a + 1 , a + n + 1);
	ll ans = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i] + 1; j <= 5001; j++) ans = (ans + f[j]) % mod;
		f[5001] = (f[5001] << 1) % mod;
		for (int j = 5001 - a[i]; j <= 5000; j++) f[5001] = (f[5001] + f[j]) % mod;
		for (int j = 5000; j >= a[i]; j--) f[j] = (f[j] + f[j - a[i]]) % mod;
	}
	printf("%lld" , ans);
	return 0;
}
