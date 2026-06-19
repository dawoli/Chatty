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
const int N = 5e5 + 10,M = (1ll << 21);
int n,k,a[N],s[N],f[N],g[N],last[M];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(); k = read();
	for(int i = 1;i <= n;i++)	a[i] = read(),s[i] = s[i - 1] ^ a[i];
	memset(last,-1,sizeof(last));
	last[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		int j = last[s[i] ^ k] + 1;
		if(j != 0)	f[i] = g[j - 1] + 1;
		g[i] = max(f[i],g[i - 1]);
		last[s[i]] = i;
	}
//	for(int i = 1;i <= n;i++)	writeln(f[i]);
	writeln(*max_element(f + 1,f + n + 1));
	return 0;
}

