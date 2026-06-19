#include <bits/stdc++.h>
using namespace std;
int t, d[100005], v[100005], a[100005], p[100005], fine[1000005];
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		int ans = 0;
		for(int i = 1; i <= 100000; i++) d[i] = v[i] = a[i] =p[i] = fine[i] = 0;
		int n, m, L, V;
		cin >> n >> m >> L >>V;
		for(int i = 1; i <= n; i++)
			cin >> d[i] >> v[i] >> a[i];
		for(int i = 1; i <= m;i++)
			cin >> p[i];
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
			{
				if(v[i] > V)
				{
					fine[d[i]]++;
				} 
			}
			if(a[i] > 0)
			{
				int dis=(V*V-v[i]*v[i]+2*a[i]-1)/(2*a[i]);
				if(dis+d[i] < L)
				{
					fine[dis+d[i]]++;
				}
			}
			
		}
		for(int i = 1; i <= p[m]; i++)
		{
			fine[i] = fine[i-1]+fine[i];
		}
		
		cout << fine[p[m]] << ' ';
		cout << 1 << endl;
	}
	return 0;
}
