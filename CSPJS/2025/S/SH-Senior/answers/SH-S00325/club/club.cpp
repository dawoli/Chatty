#include <bits/stdc++.h>
using namespace std;
#define int long long
int yihao[100010],erhao[100010],sanhao[100010];

template <typename T> void read(T &t)
{
	char c = getchar();
	int f = 1;
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
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,yiNow = 0,erNow = 0,sanNow = 0;
	read(t);
	while(t--)
	{
		int n,a,b,c,ans = 0;
		read(n);
		yiNow = erNow = sanNow = 0;
		for(int i = 1; i <= n; i++)
		{
			read(a),read(b),read(c);
			if(a >= b && a >= c)
				yihao[++yiNow] = -max(b - a,c - a),ans += a;
			else if(b >= a && b >= c)
				erhao[++erNow] = -max(a - b,c - b),ans += b;
			else
				sanhao[++sanNow] = -max(a - c,b - c),ans += c;
		}
		int shangjie = n / 2;
		if(yiNow > shangjie)
		{
			sort(yihao + 1,yihao + yiNow + 1);
			for(int i = 1; i <= yiNow - shangjie; i++)
				ans -= yihao[i];
		}
		else if(erNow > shangjie)
		{
			sort(erhao + 1,erhao + erNow + 1);
			for(int i = 1; i <= erNow - shangjie; i++)
				ans -= erhao[i];
		}
		else if(sanNow > shangjie)
		{
			sort(sanhao + 1,sanhao + sanNow + 1);
			for(int i = 1; i <= sanNow - shangjie; i++)
				ans -= sanhao[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
