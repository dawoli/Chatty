#include<iostream>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
bool a[505];
int n , m , b[505];
ll ans = 0;
void dfs(int id , ll t , int k)
{
	if (k > n - m) return;
	if (id == n + 1)
	{
		ans = (ans + 1) % mod;
		return;
	}
	ll tt = t;
	while (tt)
	{
		ll r = tt & -tt;
		dfs(id + 1 , t - r , k + (!a[id] || b[__builtin_ctz(r) + 1] <= k));
		tt -= r;
	}
}
int main()
{
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c; cin >> c;
		a[i] = c - '0';
	}
	for (int i = 1; i <= n; i++) scanf("%d" , &b[i]);
	dfs(1 , (1 << n) - 1 , 0);
	printf("%lld\n" , ans);
	return 0;
}
