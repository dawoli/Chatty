#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e6+5;
int T, n, m, L, V;
bool fl34 = true;
bool fl56 = true;
int ans1 = 0, ans2 = 0;
int p[maxn];

struct 
{
	int d;
	int v;
	int a;
}car[maxn];

int main ()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	//freopen("", "r", stdin);
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	cin >> T;
	for (register int t = 1; t <= T; t++)
	{
		//初始化 
		ans1 = 0, ans2 = 0;
		fl34 = true;
		cin >> n >> m >> L >> V;
		for (register int i = 1; i <= n; i++)
		{
			cin >> car[i].d >> car[i].v >> car[i].a;
			if (car[i].a != 0)
			{
				fl34 = false;
			}
			if (car[i].a <= 0)
			{
				fl56 = false;
			}
		}
		for (register int i = 1; i <= m; i++)
		{
			cin >> p[i];
		}
	
		//性质A：加速度为0 
	
		if (fl34)
		{
			for (register int i = 1; i <= n; i++)
			{
				if(car[i].v > V)
				{
					ans1++;
				}
			}
			cout << ans1 << " " << m-1 << endl;
		}
		
		//性质B
		
		if (fl56)
		{
			for (int i = 1; i <= n; i++)
			{
				for (double j = 0.001; j < L/V; j+=0.001)
				{
					int prv = car[i].v + car[i].a * j;
					if (prv > V)
					{
						ans1++;
						int maxpos = car[i].d +  car[i].v + 0.5 * car[i].a * pow(j, 2);
						for (int k = 1;k <= m; k++)
						{
							if (p[k] >= maxpos)
							{
								ans2++; 
							}
						}
					}
					
				}
			}
			if (ans2 >= 1)
			{
				cout << ans1 << " " << ans2-1 << endl; 
			}
			else
			{
				cout << ans1 << " " << '0' << endl;
			}
		} 
	}
	
	return 0;
}
