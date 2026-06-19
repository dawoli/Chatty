#include<bits/stdc++.h>
using namespace std;
long long n,cnts;
struct tw
{
	long long cnt;
	bool f[25];
}a[500005],k;
struct pair2
{
	long long a;
	long long b;
}s[500005];
long long x,ans,b[25][500005];
bool cmp(pair2 x2,pair2 y2)
{
	return x2.b > y2.b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> x;
	while(x >= 1)
	{
		k.f[++k.cnt] = x % 2;
		x /= 2;
	}
	for(long long i = 1;i <= n;i++)
	{
		cin >> x;
		while(x >= 1)
		{
			a[i].f[++a[i].cnt] = x % 2;
			x /= 2;
		}
	}
	for(long long i = 1;i <= 20;i++)
	{
		for(long long j = 1;j <= n;j++)
		{
			b[i][j] = b[i][j-1] + a[j].f[i];
		}
	}
	for(long long i = 1;i <= n;i++)
	{
		for(long long j = i;j <= n;j++)
		{
			bool flag = true;
			for(long long k2 = 1;k2 <= 23;k2++)
			{
				if((b[k2][j] - b[k2][i-1]) % 2 != k.f[k2])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				s[++cnts].a = i;
				s[cnts].b = j;
			}
		}
	}
	sort(s+1,s+cnts+1,cmp);
	long long l = 1e9;
	for(long long i = 1;i <= cnts;i++)
	{
		if(s[i].b < l)
		{
			ans++;
			l = s[i].a;
		}
		else if(s[i].a > l)
		{
			l = s[i].a;
		}
	}
	cout << ans;
	return 0;
}
