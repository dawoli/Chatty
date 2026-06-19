#include <iostream>
#include <algorithm>
using namespace std;

#define int long long 
int f[1000005];
int find(int a)
{
	return (f[a] == a ? a : f[a] = find(f[a]));
}
int merge(int a,int b)
{
	if (find(a) != find(b))
	{
		int fa = find(a);
		int fb = find(b);
		f[fa] = fb;
	}
}
struct node
{
	int u,v,val,c;
};

vector <pair<int,int>> map[10005];
vector <node> side;
vector <node> side_smt;
vector <node> ctr[10005];
vector <pair<int,int>> smt[10005];

bool cmp(node a,node b)
{
	return a.val < b.val;
}
bool ud[50005];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 1;i <= n+k+1;i++)
	{
		f[i] = i;	
	} 
	for (int i = 1;i <= m;i++)
	{
		int u,v,val;
		cin >> u >> v >> val;
		map[u].push_back({v,val});
		map[v].push_back({u,val});
		side.push_back({u,v,val});
	}
	for (int i = 1;i <= k;i++)
	{
		int c;
		cin >> c; 
		for (int j = 1;j <= n;j++)
		{
			int val;
			cin >> val;
			ctr[i+n].push_back({i+n,j,val,c});
		}
	}
	sort(side.begin(),side.end(),cmp);
	int sum = 0; 
	for (auto v : side)
	{
		if (find(v.u) != find(v.v))
		{ 
			sum += v.val;
			merge(v.u,v.v);
			side_smt.push_back({v.u,v.v,v.val});
			
		}
	}
	int minn = sum;
	for (int i = 1;i <= (1 << (k));i+=1)
	{
		int cost = 0;
		vector <node> side_smt_cp = side_smt;
		for (int j = 0;j < k;j++)
		{
			if ((i >> j) & 1)
			{
				cost += ctr[j+n+1][0].c;
				for (node u : ctr[j+n+1])
				{
					side_smt_cp.push_back(u);
				}
			}
		}	
		for (int i = 1;i <= n+k+1;i++)
		{
			f[i] = i;	
		}
		
		sort(side_smt_cp.begin(),side_smt_cp.end(),cmp);
		int sum = 0; 
		for (auto v : side_smt_cp)
		{
			if (find(v.u) != find(v.v))
			{ 
				sum += v.val;
				merge(v.u,v.v);
			}
		}
		minn = min(minn,sum+cost);
	}
	cout << minn << endl;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
