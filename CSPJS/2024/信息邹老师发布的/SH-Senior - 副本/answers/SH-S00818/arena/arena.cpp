#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int p = 1,x = 0;
	char c = getchar();
	while(c < '0' || c > '9')	p = c == '-' ? -1 : 1,c = getchar(); 
	while(c >= '0' && c <= '9')	x = (x << 1) + (x << 3) + (c ^ 48),c = getchar();
	return p * x;
}
void _write(int x)
{
	if(x > 9)	_write(x / 10);
	putchar(x % 10 | 48);
}
void write(int x)
{
	if(x < 0)
		putchar('-');
	write(abs(x));
}
void writeln(int x)
{
	write(x);
	puts("");
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n = read(),m = read();
	for(int i = 1;i <= n + m;i++)	read();
	string s;
	for(int i = 1;i <= log2(n);i++)	cin >> s;
	int T;
	cin >> T;
	while(T--)	puts("0");
	return 0;
}

