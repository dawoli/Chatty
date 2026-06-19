#include <bits/stdc++.h>
using namespace std;

int T,n,m,L,V,C,d[100010],v[100010],a[100010],p[100010],dp[30][30];

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		bool A = 1,B = 1;
		C = 0;
		cin >> n >> m >> L >> V;
		for(int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i] != 0)
			{
				A = 0;
			}
			if(a[i] <= 0)
			{
				B = 0;
			}
		}
		for(int i = 1;i <= m;i++)
		{
			scanf("%d",&p[i]);
		}
		if(A)
		{
			for(int i = 1;i <= n;i++)
			{
				if(v[i] > V)
				{
					if(d[i] <= p[m])
					{
						C++;
					}
				}
			}
			printf("%d %d\n",C,m - (C != 0));
			continue;
		}
		if(B)
		{
			for(int i = 1;i <= n;i++)
			{
				if(d[i] > p[m])
				{
					continue;
				}
				if(d[i] == p[m] && v[i] == V)
				{
					continue;
				}
				if(v[i] >= V)
				{
					C++;
					continue;
				}
				if(d[i] + double((V - v[i]) * v[i]) / a[i] + double((V - v[i]) * (V - v[i])) / (a[i] * 2) < p[m])
				{
					C++;
				}
			}
			printf("%d %d\n",C,m - (C != 0));
			continue;
		}
		
	}
	return 0;
}

