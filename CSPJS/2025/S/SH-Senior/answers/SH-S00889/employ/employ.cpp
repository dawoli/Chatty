#include <bits/stdc++.h>
#define int long long
using namespace std;
#define gc getchar()
#define pc putchar
#define pii pair<int,int>
#define mod 998244353ll
int read()
{
	int p = 1,x = 0;
	char c = gc;
	while(c < '0' || c > '9')	p == c == '-' ? -1 : 1,c = gc;
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = gc;
	return p * x;
}
template<typename _Tp> void _write(_Tp x) { if(x > 9) _write(x / 10); pc(x % 10 | 48); }
template<typename _Tp> void write(_Tp x) { if(x < 0) x = -x,pc('-'); _write(x); }
template<typename _Tp> void writeln(_Tp x) { write(x); puts(""); }
const int N = 510;
int n,m,a[N],b[N],ans = 0;
string s;
bool check()
{
	int cnt = 0,failed = 0;
	for(int i = 1;i <= n;i++)
		if(failed < a[b[i]] && s[i - 1] == '1')	cnt++;
		else	failed++;
	return cnt >= m;
}
int mul(int n)
{
	int ans = 1;
	for(int i = 2;i <= n;i++)	(ans *= i) %= mod;
	return ans;
}
int power(int a,int b,int p)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)	ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(); m = read();
	cin >> s;
	int cnt = 0;
	for(int i = 0;i < s.size();i++)
		if(s[i] == '1')	cnt++;
	for(int i = 1;i <= n;i++)	a[i] = read();
	if(cnt < m)	puts("0");
	else if(n <= 10)
	{
		for(int i = 1;i <= n;i++)	b[i] = i;
		do
		{
			if(check())	ans++;
		}while(next_permutation(b + 1,b + n + 1));
		writeln(ans);
	}
	else if(m == 1)
	{
		int k = s.find("1");
		if(k == -1)	puts("0");
		else
		{
			int cnt = 0;
			for(int i = 1;i <= n;i++)
				if(a[i] >= k + 1)	cnt++;
			writeln(mul(n - 1) * cnt % mod);
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)	b[i] = i;
		do
		{
			if(check())	ans++;
		}while(next_permutation(b + 1,b + n + 1));
		writeln(ans);
	}
	return 0;
}
