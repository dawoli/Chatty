#include <bits/stdc++.h>
using namespace std;
int n, m, l, V;
int d[100010], v[100010], a[100010], p[100010];
int over[100010][2];//向上（下）取整
bool road[1000010];
//天灵灵 地灵灵
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);	
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int ans = 0;
		memset(road, 0, sizeof(road));
		scanf("%d%d%d%d", &n, &m, &l, &V);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &d[i], &v[i], &a[i]);
		}
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &p[i]);
			//road[p[i]] = 1;
		}
		for(int i = 1; i <= n; i++)
		{
			if(v[i] > V)
			{
				if(a[i] >= 0)
				{
					over[i][0] = d[i];
					over[i][1] = l + 1;
				}
				else
				{
					over[i][0] = d[i];
					over[i][1] = floor((V * V - v[i] * v[i]) * 1.0 / (2 * a[i])) + 1 + d[i];
				}
			}
			else
			{
				if(a[i] > 0)
				{
					over[i][0] = floor((V * V - v[i] * v[i]) * 1.0 / (2 * a[i])) + 1 + d[i];
					over[i][1] = l + 1;
				}
			}
			cout << i <<' '<< over[i][0] << ' ' << over[i][1] << endl;
			for(int j = 1;j <= m;j++)
			{
				if(over[i][0] <= p[j] && p[j] < over[i][1])
				{
					ans ++;
					break;
					cout << i << ' ' << j << endl;
				}
				
			}
		}
		cout << ans << ' ';
		cout << m-ans << endl;
	} 
	/*
	1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
	return 0;
}
