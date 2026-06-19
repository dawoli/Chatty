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
const int N = 110;
int n,m,a[N],t;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= n * m;i++)	a[i] = read();
	t = a[1]; sort(a + 1,a + n * m + 1,greater<int>());
	int x = 1,y = 1,cur = 1;
	while(a[cur] != t)
	{
		cur++;
		if((y == n && x % 2 == 1) || (y == 1 && x % 2 == 0))	x++;
		else if(x % 2 == 1)	y++;
		else	y--;
//		cout << cur << " : " << x << " " << y << endl;
	}
	write(x),pc(' '),write(y);
	return 0;
}

