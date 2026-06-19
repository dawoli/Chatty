#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 6;

// 记得开long long
// 记得检查文件读入读出

struct car
{
	ll st;
	double v;
	double a;
}a[N];

struct det
{
	ll cnt = 0;
	ll pos;
	bool used = 0;
}dect[N];

bool detcmp(det x, det y)
{
	if(x.used > y.used) return true;
	else if(x.used == y.used)
	{
		if(x.cnt > y.cnt) return true;
		else return false;
	}
	else return false;
}

void solve()
{
	ll n, m, L, V; cin >> n >> m >> L >> V;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i].st >> a[i].v >> a[i].a;
	}
	
	for(int i=1; i<=m; i++) cin >> dect[i].pos;
	sort(dect+1, dect+1+m, detcmp);
	
	for(int i=1; i<=m; i++) dect[i].used = 0; 
	
	for(int i=1; i<=n; i++)
	{
		if(a[i].v > V && a[i].a >= 0)
		{
			for(int j=1; j<=m; j++)
			{
				if(a[i].st <= dect[j].pos)
				{
					dect[j].cnt ++; 
				}
			}
		}
		else if(a[i].v <= V && a[i].a > 0)
		{
			double dist = (V*V - a[i].v*a[i].v) / (2*a[i].a);
			for(int j=1; j<=m; j++)
			{
				if(a[i].st + dist <= dect[j].pos)
				{
					dect[j].cnt ++;
				}
			}
		}
		else if(a[i].v > V && a[i].a < 0)
		{
			double dist = (V*V - a[i].v*a[i].v) / (2*a[i].a);
			for(int j=1; j<=m; j++)
			{
				if(a[i].st <= dect[j].pos && dect[j].pos < a[i].st + dist)
				{
					dect[j].cnt ++; 
				}
			}
		}
	}
	
	ll ov = 0;
	for(int i=1; i<=n; i++)
	{	
		sort(dect+1, dect+1+m, detcmp);
		
		if(a[i].v > V && a[i].a >= 0)
		{
			for(int j=1; j<=m; j++)
			{
				if(a[i].st <= dect[j].pos)
				{
					ov ++;
					dect[j].used = 1;
					break;
				}
			}
		}
		else if(a[i].v <= V && a[i].a <= 0) continue;
		else if(a[i].v == V && a[i].a == 0) continue;
		else if(a[i].v <= V && a[i].a > 0)
		{
			double dist = (V*V - a[i].v*a[i].v) / (2*a[i].a);
			for(int j=1; j<=m; j++)
			{
				if(a[i].st + dist <= dect[j].pos)
				{
					ov ++;
					dect[j].used = 1;
					break;
				}
			}
		}
		else if(a[i].v > V && a[i].a < 0)
		{
			double dist = (V*V - a[i].v*a[i].v) / (2*a[i].a);
			for(int j=1; j<=m; j++)
			{
				if(a[i].st <= dect[j].pos && dect[j].pos < a[i].st + dist)
				{
					ov ++;
					dect[j].used = 1;
					break;
				}
			}
		}
	}
	
	ll cnt = 0;
	for(int i=1; i<=m; i++)
	{
		if(!dect[i].used) cnt ++;
	}
	
	cout << ov << ' ' << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int _; cin >> _;
	while(_--) solve();

	return 0;	
} 
