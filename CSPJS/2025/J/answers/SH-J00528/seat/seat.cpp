#include <bits/stdc++.h>
using namespace std;
long long a[110];
bool cmp(long long x,long long y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	scanf("%d%d",&n,&m);
	for (long long i = 1;i <= n * m;i++)
	{
		scanf("%d",&a[i]);
	}
	long long s = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	long long cur = 1;
	for (long long j = 1;j <= m;)
	{
		for (long long i = 1;i <= n;i++)
		{
			if (a[cur] == s)
			{
				printf("%d %d",j,i);
				return 0;
			}
			cur++;
		}
		j++;
		if (j > m) break;
		for (long long i = n;i >= 1;i--)
		{
			if (a[cur] == s)
			{
				printf("%d %d",j,i);
				return 0;
			}
			cur++;
		}
		j++;
	}
	return 0;
}
