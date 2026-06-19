#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;

int n, q;
struct node{int x, y, z, w;};

bool cmp(node a, node b)
{
	if(a.x - a.y != b.x - b.y) return a.x - a.y < b.x - b.y;
	return a.x < b.x;
}

node a[200005];

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		string s, m;
		cin >> s >> m;
		for(int j = 0; j <= s.size()-1; j++)
		{
			if(s[j] == 'b')
			{
				a[i].x = j+1;
				a[i].z = s.size()-j;
				break;
			}
		}
		for(int j = 0; j <= m.size()-1; j++)
		{
			if(m[j] == 'b')
			{
				a[i].y = j+1;
				a[i].w = m.size()-j;
				break;
			}
		}
	}
	sort(a+1, a+n+1, cmp);
	for(int i = 1; i <= q; i++)
	{
		string s, m;
		cin >> s >> m;
		int x0, y0, z0, w0;
		for(int j = 0; j <= s.size()-1; j++)
		{
			if(s[j] == 'b')
			{
				x0 = j+1;
				z0 = s.size()-j;
				break;
			}
		}
		for(int j = 0; j <= m.size()-1; j++)
		{
			if(m[j] == 'b')
			{
				y0 = j+1;
				w0 = m.size()-j;
				break;
			}
		}
		int l = 1, r = n, i1, i2, mid;
		while(l <= r)
		{
			mid = (l+r)/2;
			if(a[mid].x - a[mid].y < x0-y0)
			{
				i1 = mid;
				l = mid+1;
			}
			else
			{
				r = mid-1;
			}
		}
		l = 1, r = n;
		while(l <= r)
		{
			mid = (l+r)/2;
			if(a[mid].x - a[mid].y > x0-y0)
			{
				i2 = mid;
				r = mid-1;
			}
			else
			{
				l = mid+1;
			}
		}
		i1--;
		i2++;
		if(i1 >= i2)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for(int j = i1; j <= i2; j++)
		{
			if(a[j].x - a[j].y == x0-y0 && a[j].x <= x0 && a[j].z <= z0 && 1<=j&&j<=n)
			{
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
