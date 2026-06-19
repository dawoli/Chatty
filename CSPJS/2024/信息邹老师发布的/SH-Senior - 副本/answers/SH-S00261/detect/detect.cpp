#include <bits/stdc++.h>
using namespace std;

struct Car
{
	int d;
	int v;
	int a;
};

int t, n, m, l, v;
int p[100001], os[100001];
Car c[100001];
int ans, sum;
bool flag;

int d_search(int ad)
{
	for(int k = 1; k <= n; k++)
	{
		if(p[k] >= ad) return k;
	}
}

bool speed_check(int cd, int cv, int ca)
{
	if(cd > p[m]) return false;
	if(ca == 0)
	{
		if(cv <= v) return false;
		else return true;
	}
	else if(ca > 0)
	{
		float cs = (p[m]-cd)*ca*2+cv*cv;
		cs = sqrt(cs);
		if(cs <= v) return false;
		else return true;
	}
	else
	{
		int na = d_search(cd);
		float cs = (p[na]-cd)*ca*2+cv*cv;
		if(cs < 0) return false;
		cs = sqrt(cs);
		if(cs <= v) return false;
		else return true;
	}
	return false;
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--)
	{
		ans = 0, sum = 0;
		scanf("%d%d%d%d", &n, &m, &l, &v);
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &c[i].d, &c[i].v, &c[i].a);
		for(int i = 1; i <= m; i++) scanf("%d", &p[i]);
		for(int i = 1; i <= n; i++)
		{
			flag = speed_check(c[i].d, c[i].v, c[i].a);
			if(flag == true)
			{
				int na = d_search(c[i].d);
				for(int j = na; j <= m; j++)
				{
					float cs = (p[j]-c[i].d)*c[i].a*2+c[i].v*c[i].v;
					if(cs < 0) continue;
					cs = sqrt(cs);
					if(cs > v) os[j]++;
				}
				ans++;
			}
		}
		for(int i = 1; i <= m; i++)
		{
			if(os[i]-os[i-1] > 0 && flag == false)
			{
				flag = true;
				sum++;
			}
			if(os[i]-os[i-1] < 0) flag = false;
		}
		printf("%d %d\n", ans, m-sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
