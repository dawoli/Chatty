#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e5+10;
const int M = N;
int T,n,m,L,V;
int p[N] , d[N] , v[N],a[N],ans1 , ans2;
bool vis[N];


void _init()
{
	memset(p,0,sizeof(p));
	memset(d , 0 , sizeof(d));
	memset(v , 0,sizeof(v));
	memset(a , 0 , sizeof(a));
	memset(vis , 0, sizeof(vis));
	ans1 = 0;
	ans2 = 0;
}

inline void solve()
{
	cin >> n >> m >> L >> V;
	for(int i = 1;i<=n;i++)
	{
		cin >> d[i] >> v[i] >> a[i];
	}
	
	for(int i = 1;i<=m;i++) cin >> p[i];
	
	sort(p+1 , p+1+m);
	
	for(int i = 1;i<=n;i++)
	{
		int where_p = upper_bound(p+1, p+1+m , d[i]) - p;
		if(a[i] == 0)
		{
			
			if(v[i] > V && d[i] <= p[m])
			{
				vis[m] = 1;
				ans1++;
			//	cout << i << '\n';
			}
		}
		else if(a[i] < 0)
		{
			double delta_x = (V*V - v[i]*v[i])/(2*a[i]+0.0);
			if(delta_x <= 0) continue;
			
			where_p = upper_bound(p+1 , p+1+n , d[i]) - p;
			
			int start = (p[where_p-1] == d[i])?(where_p - 1) :(where_p);
			bool f= 0 ;
			while(p[start] < d[i] + delta_x)
			{
				if(vis[start])
				{
					ans1++;
					f = 1;
					break;
				}
				start++;
			}
			if(f) continue;
			else 
			{
				start = (p[where_p-1] == d[i])?(where_p - 1) :(where_p);
				vis[start] = 1;
				ans1++;
			}
		}
		
		else
		{
			if(d[i] > p[m]) continue;
			
			if(d[i] == p[m] && v[i] > V)
			{
				vis[m] = 1;
				ans1++;
				continue;
			}
			
			//else continue;
			
			if(v[i] > V)
			{
				vis[m] = 1;
				ans1++;
				continue;
			}
			double delta_x = (V*V - v[i]*v[i])/(2*a[i] + 0.0);
			
			
			if(delta_x < 0)
			{
				vis[m] = 1;
				ans1++;
			//	cout << i << '\n';
			}
			else if(d[i] + delta_x < p[m])
			{
				vis[m] = 1;
				ans1++;
			//	cout << i << '\n';
			}
			else continue;
		}
	}
	
	for(int i =1;i<=m;i++)
	{
		if(vis[i] == 0) ans2++; 
	}
	
	cout << ans1 << " " << ans2 << '\n';
}

int main()
{
	freopen("detect.in" , "r" , stdin);
	freopen("detect.out" , "w" , stdout);
	cin >> T;
	while(T--)
	{
		_init();
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
