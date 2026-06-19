#include<iostream> 

using namespace std;

int t,n,m,L,V,sum;
int d[100005],v[100005],a[100005],p[100005];

int calculate(int di,int vi,int ai)
{
	if(ai == 0)
	{
		if (vi <= V)
		{
			return -1;
		}
		if (vi > V)
		{
			for (int i = 1;i <= m;i++)
			{
				if (p[i] >= di)
				{
					return p[i];
				}
			}	
		}
	}
	else if (ai < 0)
	{
		int q = 0,dt = 0,b = 0;
		q = (V * V - vi * vi) / (2 * ai);
		dt = di + q;
		if (vi > V)
		{
			for (int i = 1;i <= m;i++)
			{
				if(p[i] >= dt && p[i-1] < di)
				{
					return -1;
				}
				if (p[i] < dt && p[i] >= di)
				{
					return p[i];
				}
			}
		}
		if (vi < V)
		{
			return -1;
		}
	}
	else if (ai > 0)
	{
		int q = 0,dt = 0,b = 0;
		q = (V * V - vi * vi) / (2 * ai);
		dt = di + q;
		if (vi > V)
		{
			for (int i = 1;i <= m;i++)
			{
				if (p[i] >= di)
				{
					return p[i];
				}
			}
		}
		if (vi < V)
		{
			if (dt >= L && p[m] != L)
			{
				return -1;
			}
			else
			{
				for (int i = 1;i <= m;i++)
				{
					if (p[i] >= di)
					{
						return p[i];
					}
				}
			}
		}
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	cin >> n >> m >> L >> V;
	sum = n;
	
	for (int j = 1;j <= t;j++)
	{
		for (int i = 1;i <= n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
		}
		for (int i = 1;i <= m;i++)
		{
			cin >> p[i];
		}
		for (int i = 1;i <= n;i++)
		{
			if (calculate(d[i],v[i],a[i]) == -1)
			{
				sum = sum - 1;
			}
		}
		cout << sum << " " << sum;
	}
	
	return 0;
} 
