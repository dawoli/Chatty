#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

int n, m, L, V;
const int NR = 100005;
int s[1000005];
int p[NR], d[NR], v[NR], a[NR];
int l[NR], r[NR];

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> L >> V;
		for(int i = 1; i <= n; i++)
		{
			l[i] = 0;
			r[i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int i = 1; i <= m; i++)
		{
			cin >> p[i];
		}
		int pos = 0;
		for(int i = 1; i <= L; i++)
		{
			if(p[pos+1] == i) pos++;
			s[i] = pos;
		}
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 0)
			{
				if(v[i] > V)
				{
					l[i] = d[i];
					r[i] = L;
				}
			}
			if(a[i] > 0)
			{
				if(v[i] > V)
				{
					l[i] = d[i];
					r[i] = L;
				}
				if(v[i] <= V)
				{
					if((V*V-v[i]*v[i])%(2*a[i]) == 0)
					{
						int dd = d[i]+(V*V-v[i]*v[i])/(2*a[i]);
						if(dd < L)
						{
							l[i] = dd+1;
							r[i] = L;
						}
					}
					else
					{
						int dd = d[i]+(V*V-v[i]*v[i])/(2*a[i]);
						if(dd+1<=L)
						{
							l[i] = dd+1;
							r[i] = L;
						}
					}
				}
			}
			if(a[i] < 0 && v[i] > V)
			{
				if((v[i]*v[i]-V*V)%(0-2*a[i])==0)
				{
					int dd = d[i]+(v[i]*v[i]-V*V)/(0-2*a[i]);
					if(dd <= L)
					{
						l[i] = d[i];
						r[i] = dd-1;
					}
					if(dd > L)
					{
						l[i] = d[i];
						r[i] = L;
					}
				}
				else
				{
					int dd = d[i]+(v[i]*v[i]-V*V)/(0-2*a[i]);
					if(dd+1 <= L)
					{
						l[i] = d[i];
						r[i] = dd;
					}
					if(dd+1 > L)
					{
						l[i] = d[i];
						r[i] = L;
					}
				}
			}
		}
		int ans1 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[r[i]] - s[l[i]-1] > 0)
			{
				ans1++;
			}
		}
		cout << ans1 << " " << m-1<< endl;
	}
	

	return 0;
}
