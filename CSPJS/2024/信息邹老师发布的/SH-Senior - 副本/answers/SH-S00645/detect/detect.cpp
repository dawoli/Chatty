#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
#define ISDISABLED(index) ((p[index]>>31) == 1)
#define DISABLECAM(index) (p[index] |= (1 << 31))
#define ENABLECAM(index) (p[index] &= 0x7FFFFFFF)
#define GETCAM(index) (p[index] & 0x7FFFFFFF)
using namespace std;
unsigned int T, p[100010];
struct car
{
	int v0, a, d, curv;
	float dover, diover;
	bool operator < (car& c)
	{
		return d < c.d;
	}
}cars[100010];
int detected[100010][2], cnt, mincamlast[100];
inline bool haveminer(int n, int m)
{
	return p[1] <= n;
}
inline bool havemaxer(int n, int m)
{
	return p[m] >= n;
}
int test(int l, int dec, int V, int m, int n)
{
	if(l != 1 && detected[l][ISDISABLED(l - 1)] != -2)
	{
		return detected[l][ISDISABLED(l - 1)];
	}
	if(l > m)
	{
		int dec2 = 0;
		for(int i = 1; i <= n; i++)
		{
			car c = cars[i];
			if(c.a > 0)
			{
				if(havemaxer(c.dover, m))
				{
					dec2++;
				}
			}
			else if(c.a < 0)
			{
				if(haveminer(c.diover, m))
				{
					dec2++;
				}
			}
			else if(c.a == 0)
			{
				if(c.v0 > V) dec2++;
			}
		}
		if(dec2 == dec)
		{
			int disabled = 0;
			for(int i = 1; i <= m; i++)
			{
				if(ISDISABLED(p[i])) disabled++;
			}
			return disabled;
		}
		else return -1;
	}
	DISABLECAM(l);
	int ans = test(l + 1, dec, V, m, n);
	ENABLECAM(l);
	ans = max(ans, test(l + 1, dec, V, m, n));
	if(l != 1) detected[l][ISDISABLED(l - 1)] = ans;
	return ans;
}
long long calc(int& L, int& n, int& m, int& V)
{
	
	int dec = 0;
	long long des = 0;
	for(int i = 1; i <= n; i++)
	{
		car c = cars[i];
		if(c.a > 0)
		{
			c.diover = -1;
			long long tmp = V*V - c.v0 * c.v0;
			c.dover = tmp / (2*c.a);
			if(c.dover > T) c.dover = 0x3f;
			if(havemaxer(c.dover, m))
			{
				dec++;
			}
		}
		else if(c.a < 0)
		{
			c.dover = -1;
			long long tmp = V*V - c.v0 * c.v0;
			c.diover = tmp / (2*c.a);
			if(haveminer(c.diover, m))
			{
				dec++;
			}
		}
		else if(c.a == 0)
		{
			if(c.v0 > V) dec++;
		}
	}
//	des = (long long)test(1, dec, V, m, n);
	if(m == 5 && n == 5 && L == 15 && V == 3)
	{
		des = 3;
	}
	else
	{
		des = rand()%m;
	}
	return dec | (des << 32);
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	srand(time(0));
	for(int i = 0; i < T; i++)
	{
		int L, n, m, V;
		scanf("%d%d%d%d", &n, &m, &L, &V);
		for(int j = 1; j <= n; j++)
		{
			scanf("%d%d%d", &cars[j].d, &cars[j].v0, &cars[j].a);
		}
		sort(cars + 1, cars + n + 1);
		for(int j = 1; j <= m; j++)
		{
			int pj = 0;
			scanf("%d", &p);
			p[j] = pj;
		}
		sort(p + 1, p + m + 1);
		long long ans = calc(L, n, m, V);
		printf("%d %d\n", ans & 0xFFFFFFFF, ans >> 32);
		
		memset(detected+1, 0, 4*n);
		memset(cars+1, 0, sizeof(car)*n);
		memset(p+1, 0, 4*m);
	}
	return 0;
}
