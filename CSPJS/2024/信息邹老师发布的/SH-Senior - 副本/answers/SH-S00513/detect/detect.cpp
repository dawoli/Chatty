#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
	double ai,bi;
}a[100005];
int b[100005] = {};
bool cmp1(int x,int y)
{
	return x < y;
}
bool cmp2(node x,node y)
{
	return x.ai < y.ai;
}
bool cmp3(node x,node y)
{
	return x.bi < y.bi;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i ++)
	{
		memset(a,{},sizeof(a));
		int n,m,l,v,cnt = 0;
		cin >> n >> m >> l >> v;
		for (int j = 1; j <= n; j ++)
		{
			int dj,vj,aj;
			cin >> dj >> vj >> aj;
			if (aj == 0)
			{
				if (vj > v)
				{
					a[++ cnt].ai = dj;
					a[cnt].bi = l;
				}
			}
			if (aj > 0)
			{
				if (vj > v)
				{
					a[++ cnt].ai = dj;
					a[cnt].bi = l;
				}
				else
				{
					double x = dj + 1.0 * (v * v - vj * vj) / (2 * aj) + 0.000001;
					if (x <= l)
					{
						a[++ cnt].ai = x;
						a[cnt].bi = l;
					}
				}
			}
			if (aj < 0)
			{
				if (vj > v)
				{
					double x = dj + 1.0 * (v * v - vj * vj) / (2 * aj) - 0.000001;
					a[++ cnt].ai = dj;
					if (x <= l)
					{
						a[cnt].bi = x;
					}
					else
					{
						a[cnt].bi = l;
					}
				}
			}
		}
		n = cnt;
		memset(b,0,sizeof(b));
		for (int j = 1; j <= m; j ++)
		cin >> b[j];
		sort(a + 1,a + n + 1,cmp2);
		sort(b + 1,b + m + 1,cmp1);
		int ia = 1,ja = 1;
		cnt = 0;
		while (ia <= n && ja <= m)
		{
			while (b[ja] < a[ia].ai)
			ja ++;
			if (a[ia].bi >= b[ja])
			cnt++;
			ia ++;
		}
		cout << cnt << " ";
		
		cnt = 0;
		int ic = 0;
		sort(a + 1,a + n + 1,cmp3);
		bool flag = 0;
		for (int j = 1; j <= n; j ++)
		{
			if (flag != 0 && (a[j].ai <= b[ic] || ic == m || a[j].bi < b[ic + 1]))
			{
				continue;
			}
			int it = ic;
			while (ic < m && b[ic + 1] <= a[j].bi)
			ic ++;
			if (a[j].ai > b[ic])
			{
				ic = it;
			}
			else
			{
				flag = 1;
				cnt ++;
			}
		}
		cout << m - cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
