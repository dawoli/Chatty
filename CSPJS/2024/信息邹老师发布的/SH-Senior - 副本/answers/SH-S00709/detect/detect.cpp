#include <bits/stdc++.h>
using namespace std;
int n,m,l,V,cnt = 0,minn = 1e9;
int p[100005];
vector<int> cntp[100005];
bool check(int l,int r)
{
	for(int i = 1;i <= m;i++)
	{
		if(p[m] >= l && p[m] <= r)
		{
			return true;
		}
	}
	return false;
}
struct Car{
	int d,v,a,el,er,fu,fd;
	void cafd()
	{
		fu = V * V - v * v;
		fd = 2 * a;
	}
}c[100005];
bool cmp(vector<int> x,vector<int> y)
{
	return x.size() > y.size();
}
void dfs(int p,set<int> st,int sum)
{
	if(p > m) 
	{
		if(st.size() == cnt)
		{
//			cout << sum << endl;
			minn = min(minn,sum);
		}
		return;
	}
	dfs(p + 1,st,sum);
	set<int> tmp = st;
	for(int i = 0;i < cntp[p].size();i++)
	{
		tmp.insert(cntp[p][i]);
//		cout << cntp[p][i] << " ";
	}
//	cout << endl;
	dfs(p + 1,tmp,sum + 1);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> l >> V;
		for(int i = 1;i <= n;i++)
		{
			cin >> c[i].d >> c[i].v >> c[i].a;
			c[i].cafd();
//			cout << c[i].fu << " " << c[i].fd << endl;
		}
		for(int i = 1;i <= m;i++)
		{
			cin >> p[i];
		}
		// the first task
		for(int i = 1;i <= n;i++)
		{
			if(c[i].a > 0)
			{
				int k = ceil(1.0 * c[i].fu / c[i].fd);
				if(!check(c[i].d + k,l))
				{	 
					cnt++;
				}
				c[i].el = c[i].d + k;
				c[i].er = l;
			}
			else if(c[i].a == 0)
			{
				if(c[i].v <= V || (c[i].v > V && !check(c[i].d,l)))
				{
					cnt++;
				}
				c[i].el = c[i].d;
				c[i].er = l;
			}
			else if(c[i].a < 0)
			{
				int k = floor(1.0 * c[i].fu / c[i].fd);
//				cout << c[i].fu << " " << c[i].fd << endl;
				if(!check(c[i].d,c[i].d + k))
				{
					cnt++;
				}
				c[i].el = c[i].d;
				c[i].er = c[i].d + k;
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			cout << "eler:" << c[i].el << " " << c[i].er << endl;
//		}
		cout << cnt << " " << endl;
		// the second task
		for(int i = 1;i <= m;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(p[i] >= c[j].el && p[i] <= c[j].er)
				{
					cntp[i].push_back(j);
				}
			}
		}
		sort(cntp + 1,cntp + m + 1,cmp);
//		for(int i = 1;i <= m;i++)
//		{
//			for(int j = 0;j < cntp[i].size();j++)
//			{
//				cout << cntp[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
		set<int> s;
		dfs(1,s,0);
		cout << m - minn - 1 << endl;
	}
	return 0;
}
