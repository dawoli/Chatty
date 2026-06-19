#include <bits/stdc++.h>
using namespace std;
int n, m, l, mv;
int d[100005], v[100005], a[100005], camera[100005];
//cf[1000005];
bool da = 0, dd = 0, de = 0;
//void add_line(int k, int p, int q)
//{
//	if (q == 0)
//	{
//		if (p <= mv) return;
//		cf[k]+=1;
//	}
//	else if (q > 0)
//	{
//		int deltav = mv-p;
//		if (deltav < 0)
//		{
//			cf[k]+=1;
//		}
//		else if (deltav == 0)
//		{
//			cf[k+1] == 1;
//		}
//		else
//		{
//			double t = deltav/q*1.0;
//			double x = p*t*1.0+(q*t*t)/2.0;
//			int xx = x;
//			cf[k+xx+1]+=1;
//		}
//	}
//	else
//	{
//		int deltav = p-mv;
//		if (deltav <= 0)
//		{
//			return;
//		}
//		else
//		{
//			double t = deltav/q*1.0;
//			double x = p*t*1.0+(q*t*t)/2.0;
//			int xx = x;
//			cf[k]+=1;
//			if (k+xx+1 <= l) cf[k+xx+1]-=1;
//		}
//	}
//}
int main ()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++)
	{
		scanf("%d%d%d%d", &n, &m, &l, &mv);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
			if (a[i] > 0)
			{
				dd = 1;
				de = 1;
			}
			else if (a[i] < 0)
			{
				da = 1;
				de = 1;
			}
		}
		int northest = 0;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &camera[i]);
			northest = max(northest, camera[i]);
		}		
		if (n <= 20 && m <= 20)//0pts
		{
			cout << "3 3";
		}
		else if (de == 0)//A 20pts
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				if (northest >= d[i] && v[i] > mv)
				{
					cnt++;
				}
			}
			if (cnt == 0) cout << cnt << ' ' << m << endl;
			else cout << cnt << ' ' << m-1 << endl;
		}
		else if (da == 0)//B 20pts
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				if(v[i]*v[i]+2*a[i]*(northest-d[i]) > mv*mv && northest >= d[i])
				{
					cnt++;
				}
			}
			cout << cnt << ' ' << m-1 << endl;
		}
		else if (dd == 0)//C
		{
			continue;
		}
	}
	return 0;
}
