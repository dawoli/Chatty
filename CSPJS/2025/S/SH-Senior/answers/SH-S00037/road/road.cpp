#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
const int M = 15;
const int MAX = (long long)(1e17);
const long double INF = 1e-6;
 
long long u[N], v[N], w[N], a[N];
long long bd[N];
long long d[N][N], d2[N][N][M];
bool la1[N][N], b1[N];
long double la2[N][N];
long long step;
long long ans;
long long ans2;



int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
		if (d[u[i]-1][v[i]-1] == 0LL || w[i] < d[u[i]-1][v[i]-1])
		{
			d[u[i]-1][v[i]-1] = w[i];
			d[v[i]-1][u[i]-1] = w[i];
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &bd[i]);
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &a[j]);
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				d2[j][k][i] = a[j] + a[k];
				d2[k][j][i] = a[j] + a[k];

			}
		}
	}
	
	if (k == 0)
	{
		for (int i = 0; i < n; i++)
		{
			long long anslayer = MAX;
			int aimi=-1, aimj=-1;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					if (la1[i][j] == false)
					{
						if (d[i][j] < anslayer && d[i][j] != 0)
						{
							anslayer = d[i][j];
							aimi = i;
							aimj = j;
						}
					}
				}
			}
			if (aimi != -1 && aimj != -1)
			{
				ans += anslayer;
				la1[aimi][aimj] = true;
				la1[aimj][aimi] = true;
			}
		}
		printf("%lld\n", ans);
	}

/////////////////////////////////////////////////////////////////////////////

	if (k != 0)
	{
		for (int i = 0; i < n; i++)
		{
			bool flaaag = false;
			for (int j = 0; j < n; j++)
			{
				if (d[i][j] != 0)
				{
					flaaag = true;
				}
			}
			if (!flaaag)
			{
				b1[i] = true;
				step++;
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			long long anslayer = MAX;
			int aimi=-1, aimj=-1;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
				
					if (la2[i][j] == 0)
					{
			
						if (d[i][j] < anslayer && d[i][j] != 0)
						{
							anslayer = d[i][j];
							aimi = i;
							aimj = j;
							
						}
					}
				}
			}
			if (aimi != -1 && aimj != -1)
			{
				ans2 += anslayer;
				la2[aimi][aimj] = 1.0*d[aimi][aimj];
				la2[aimj][aimi] = 1.0*d[aimi][aimj];

			}
		}
		
		for (int i = 0; i < k; i++)
		{
			bool steep = false;
			double tmp = 0;
			int flag = 0;
			for (int j = 0; j < n; j++)
			{
				
				
				for (int k = 0; k < n; k++)
				{
	
					if (la2[j][k] == 0)
					{
						steep = true;
						la2[j][k] = 1.0 * d2[j][k][i] + bd[i];
						la2[k][j] = 1.0 * d2[j][k][i] + bd[i];
						flag++;
					}
					else if ((1.0*la2[j][k]) > (1.0*d2[j][k][i]))
					{
						tmp += 1.0*la2[j][k] - 1.0*d2[j][k][i];
	//					cout << la2[j][k] << ' ' <<  d2[j][k][i] << endl;
						flag++;
					}
				}
			}
	
			if (tmp > 1.0*bd[i] || steep == true)
			{

				for (int j = 0; j < n; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (j != k) {
							if (la2[j][k] > d2[j][k][i])
							{
								la2[j][k] = 1.0*d2[j][k][i] + (1.0*bd[i] / (1.0*flag));
								la2[k][j] = 1.0* d2[j][k][i] + (1.0*bd[i] / (1.0*flag));
							}
						}
					}
				}
				ans2 -= (tmp-bd[i]);
		//		cout << tmp - bd[i] <<  ' ' << bd[i]<< endl;
			}
		}
		printf("%lld\n", ans2);
	}

/////////////////////////////////////////////////////////////////////////////
	return 0;
}
