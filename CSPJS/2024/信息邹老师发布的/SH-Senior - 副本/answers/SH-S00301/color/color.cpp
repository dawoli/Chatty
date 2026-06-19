#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];

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

int cal(int now)
{
	int pre0 = 0,pre1 = 0,res = 0;
	for(int i = 1; i <= n; i++)
	{
		int tmp = -1;
		if(now & (1LL << (i - 1)))
			tmp = 1;
		else
			tmp = 0;
		if((tmp == 0 && pre0 == a[i]) || (tmp == 1 && pre1 == a[i]))
			res += a[i];
		if(tmp == 0)
			pre0 = a[i];
		if(tmp == 1)
			pre1 = a[i];
	}
	return res;
}

signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int ans = 0;
		read(n);
		for(int i = 1; i <= n; i++)
			read(a[i]);
		for(int i = 0; i < (1LL << n); i++)
			ans = max(ans,cal(i));
		cout << ans << '\n';
	}
	return 0;
}
