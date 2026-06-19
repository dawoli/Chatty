#include<bits/stdc++.h>
using namespace std;
int n, m, L, V, ans, maxcam;
bool cam[100005], camn[100005], flag;
struct node
{
	int d, v, a;
}cr[100005];
struct Node
{
	int id, num;
}st[100005], ed[100005];
bool cmp(Node x, Node y)
{
	return x.num < y.num;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> n >> m >> L >> V;
	for(int i = 1; i <= n; i++)
	{
		cin >> cr[i].d >> cr[i].v >> cr[i].a;
		st[i].num= i;
		ed[i].num= i;
	}
	for(int i = 1; i <= m; i++)
	{
		int o;
		cin >> o;
		cam[o] = true;
		maxcam = max(o, maxcam);
	}
	int stm;
	for(int i = 1; i <= n; i++)
	{
		if(cr[i].a >= 0 && cr[i].d > V)
		{
			st[i].num = cr[i].d;
			ed[i].num = maxcam;
		}
		else if(cr[i].a < 0 && cr[i].d > V)
		{
			st[i].num = cr[i].d;
			stm = (V*V - cr[i].v*cr[i].v) / (2*cr[i].a);
			ed[i].num = cr[i].d + stm;
		}
		else
		{
			stm = (V*V - cr[i].v*cr[i].v) / (2*cr[i].a);
			if(cr[i].d+stm <= L)
			{
				st[i].num = cr[i].d + stm;
				ed[i].num = maxcam;
			}
		}
		for(int j = st[i].num; j <= ed[i].num; j++)
		{
			if(cam[j])
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << " ";
	ans = 0;
	sort(st+1, st+n+1, cmp);
	sort(ed+1, ed+n+1, cmp);
	int r = 1, l = 1;
	for(int i = 1; i <= n; i++)
	{
		if(st[l].num > ed[r].num)
			r++;
		if(st[l].num > ed[r-1].num)
		{
			for(int j = st[i].num ; j <= ed[i].num; j++)
			{
				if(cam[j])
					camn[j] = true;
			}
			l++;
		}
		else
		{
			for(int j = st[l].num; j <= ed[r].num; j++)
			{
				if(cam[j])
					flag = true;
			}
			if(flag)
			{
				for(int j = st[l-1].num; j <= st[l].num; j++)
				{
					camn[j] = false;
				}
			}
		}	
	}
	for(int i = 1; i <= maxcam; i++)
	{
		if(camn)
			ans++;
	}
	cout << m - ans;
	return 0;
}
