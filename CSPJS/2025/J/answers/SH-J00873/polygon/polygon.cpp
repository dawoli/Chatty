#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc getchar()
#define pc putchar
#define pair<int,int>
inline int read()
{
	int p = 1,x = 0;
	char c = gc;
	while(c < '0' || c > '9')	p = p == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
template<typename _Tp> void _write(_Tp x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename _Tp> void write(_Tp x) { if(x < 0) x = -x,pc('-'); _write(x);}
template<typename _Tp> void writeln(_Tp x) { write(x); puts(""); }
const int N = 5010;
int n,a[N];
#define mod 998244353ll
int power(int a,int b,int p)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)	ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
int ans = 0;
void dfs(int step,int sum = 0,int maxn = 0,int cnt = 0)
{
	if(step == n + 1)
	{
		if(sum > 2 * maxn && cnt >= 3)	ans++;
		return;
	}
	dfs(step + 1,sum,maxn,cnt);
	dfs(step + 1,sum + a[step],max(maxn,a[step]),cnt + 1);
}
int f[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++)	a[i] = read();
	int minn = *min_element(a + 1,a + n + 1);
	int maxn = *max_element(a + 1,a + n + 1);
	if(minn == maxn)
	{
		ans = power(2,n,mod) - 1 - n - (n * (n - 1) / 2) % mod;
		ans %= mod; (ans += mod) %= mod;
		writeln(ans); return 0;
	}
	if(n <= 20)
	{
		dfs(1);
		writeln(ans);
		return 0;
	}
	dfs(1);
	writeln(ans);
	return 0;
}

