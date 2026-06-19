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
int cnt[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
	for(int i = 0;i < s.size();i++)
		if(isdigit(s[i]))	cnt[s[i] - 48]++;
	for(int i = 9;i >= 0;i--)
		for(int j = 1;j <= cnt[i];j++)
			pc(i + 48);
	return 0;
}
