#include <bits/stdc++.h>
//using namespace std;

double L, V;
long long T, n, m, c;
double d[100010], v[100010], a[100010], t[100010];
long long p[100010], np[100010], sign[100010], p_sign[100010];
double over_speed;

void init()
{
	memset(d, 0, sizeof(d));
	memset(v, 0, sizeof(v));
	memset(a, 0, sizeof(a));
	memset(p, 0, sizeof(p));
	memset(np, 0, sizeof(np));
	memset(p_sign, 0, sizeof(p_sign));
	memset(sign, 0, sizeof(sign));
	memset(t, 0, sizeof(t));
	over_speed = 0;
	c = 0;
}

bool cmp_down(long long a, long long b)
{
	return a > b;
}

bool cmp_up(long a, long b)
{
	return a < b;
}

double ll(double x)
{
	if(x < 0) return -x;
	else return x;
}

double cal_dis(double v0, double d0, double a, double t)
{
	return  d0 + v0 * t + (0.5 * a * t * t);
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	std::cin >> T;
	while(T--){
		init();
		std::cin >> n >> m >> L >> V;
		for(long long i = 1; i <= n; i++)
			std::cin >> d[i] >> v[i] >> a[i];
		for(long long i = 1; i <= m; i++)
			std::cin >> p[i];
		std::sort(p + 1, p + 1 + m, cmp_down);
		for(long long i = n; i >= 1; i--)
			np[i] = p[++c];
			
		for(long long i = 1; i <= n; i++)
		{
			if(a[i] == 0 )
			{
				if(v[i] > V && p[1] >= d[i])
				{
					over_speed++;
					sign[i]++;
				}
			}
			else
			{
				t[i] = ll(V - v[i]) / a[i];
				if((a[i] < 0 && cal_dis(v[i], d[i], a[i], t[i]) >= np[1] && cal_dis(v[i], d[i], a[i], t[i]) <= p[1]) || (a[i] > 0 && cal_dis(v[i], d[i], a[i], t[i]) <= p[1]))
				{
					over_speed++;
					sign[i]++;							
				}
	
			}
			for(int i = 1; i <= n; i++)
			{
				if(a[i] >= 0 && sign[i] > 0)
				{
					p_sign[m] = 1;
					break;
				}  
			}
			for(long long i = 1; i <= n; i++)
			{				
				if(sign[i] > 0 || a[i] < 0)
				{
					for(long long j = 1; j <= m; j++)
					{
						if(d[i] <= p[j] && cal_dis(v[i], d[i], a[i], t[i]) >= p[j])
						{
							p_sign[j] = 1;
							break;
						}
					}					
				}
			}
			for(long long i = 1; i <= m; i++)
			{
				if(p_sign[i] > 0)
				{
					c++;
				}
			}
		}
		std::cout << over_speed << " " << (m - c) << "\n";	
	}
	return 0;
}
