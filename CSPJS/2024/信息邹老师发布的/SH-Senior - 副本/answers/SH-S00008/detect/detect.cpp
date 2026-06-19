#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int n,m,l,vmax,T;
int p[101000];
pair<int, int> car[101000];
int ans_overspeed, ans_needp;

void get_overspeed(int i, int d, int v, int a)
{
	if(a == 0)
	{
		if(v > vmax)
		{
			car[i].x = d;
			car[i].y = l;
		}
		else
		{
			car[i].x = l+1;
			car[i].y = l+1;
		}
	}
	if(a > 0)
	{
		double x = 1.0*(vmax*vmax - v*v)/(2*a);
		int mov;
		if(x - int(x) > 0) mov = int(x)+1;
		else mov = int(x)+1;
		
		car[i].x = d+mov;
		car[i].y = l;
		 
	}
	if(a < 0)
	{
		if(v > vmax)
		{
			car[i].x = d;
			double x = 1.0*(vmax*vmax - v*v)/(2*a);
			int mov;
			if(x - int(x) > 0) mov = int(x);
			else               mov = int(x)-1;
			
			car[i].y = min(d + mov , l);
		}
		else
		{
			car[i].x = l+1;
			car[i].y = l+1;
		}
	}
}

pair<int, int> ab(pair<int,int> now, pair<int,int> c)
{
//	cout << now.x << ' ' << now.y << endl;
	if(now.y < c.x) return make_pair(-1,-1);
	return make_pair(max(now.x, c.x),min(now.y, c.y));
	
}

int check(int i)
{
	for(int k = 0; k < m; k ++)
	{
		if(p[k] >= car[i].x && p[k] <= car[i].y) return 1;
		if(p[k] > car[i].y) return 0;
	}
	return 0;
}

//int ab(pair<int,int> )

pair<int,int> su(int i)
{
	int ft=0,lt=0;
	for(int k = 0; k < m; k ++)
	{
		if(p[k] >= car[i].x && p[k] <= car[i].y)
		{
			if(ft==0) ft = p[k];
			lt = p[k];
		}
		if(p[k] > car[i].y)
		{
			break;
		}
	}
	
	if(ft == 0) return make_pair(-1,-1);
	else		return make_pair(ft, lt);
}

int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
	{
		ans_overspeed = 0;
		scanf("%d%d%d%d", &n, &m, &l, &vmax);
		int d,v,a;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d%d", &d, &v, &a);
			get_overspeed(i, d, v, a);
		}
		for(int i = 0; i < m; i ++)
		{
			scanf("%d", &p[i]);
		}
		if(n<=3001)
		{
			sort(car, car+n);
			sort(p, p+m);
			queue <int> cars;
			for(int i=0; i<n; i++)
			{
				ans_overspeed += check(i);
				
			}
			cout << ans_overspeed << ' ';
			
			for(int i = 0; i < n; i ++)
			{
				car[i] = su(i);
				//cout << car[i].x << ' ' << car[i].y << endl;
			}
			pair<int,int> now;
			int d = 0;
			while(car[d].x != -1)
			{
				d++;
			}
			now=car[d];
			ans_needp = 0;
			for(int i = d; i < n; i ++)
			{
				//cout << now.x << ' ' << now.y << endl;
				if(car[i].x == -1){
					
					continue;
				} 
			
				now = ab(now, car[i]);
				if(now.x == -1)
				{
					ans_needp++;
					now = car[i];
				}
			}
			cout << m-ans_needp-1 << endl;
		}
	}
	
	
	
	
	
	return 0;
}
