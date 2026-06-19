#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T> void read(T &t)
{
	int f = 1;
	char c = getchar();
	t = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		t = (t << 3) + (t << 1) + (c ^ 48);
		c = getchar();
	}
	t *= f;
}

signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	return 0;
}
