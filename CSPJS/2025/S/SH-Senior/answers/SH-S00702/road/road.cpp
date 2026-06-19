#include<bits/stdc++.h>
#define maxn 10020
#define maxm 1000020
#define inf 0x3f3f3f3f
#define maxk 20
using namespace std;

int n, m, k;
struct stcity
{
	int side, money;
};
vector <stcity> edge[maxm];
/* 
struct sttown
{
	int bldmoney;
	int daolu[maxn];
	bool tocity=0;
	//bool xiulu[maxn]=0;
	int bcj;
	
};
sttown zhen[maxk];
*/ 
int bcj[maxn];
int ans;
vector <int> bzbcj; int bzbcjbh;
int tmp; 

bool lt ()
{
	if (bzbcj.size()==n)
		return 1;
	else 
		return 0;
}

int main()
{
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf ("%d%d%d", &n, &m,&k);
	for (int i = 1; i <= n; i++)
		bcj[i]=i;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf ("%d%d%d", &u, &v, &w);
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	if(k!=0)
	for (int i = 1; i <= k; i++)
	{
		/*
		scanf ("%d", &zhen[i].bldmoney);
		zhen[i].bcj = n+i;
		for (int j = 1; j <= n; j++) 
			scanf ("%d", &zhen[i].daolu[j]);
		*/
		scanf ("%d", &tmp);
	}
	
	if (k==0) 
	{
		int minn=inf;
		int minni, minnj, jidx;
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 0; j < edge[i].size(); j++)
			{
				if (edge[i][j].money < minn) 
				{
					minn = edge[i][j].money;
					minni = i;
					minnj = edge[i][j].side;
					jidx = j;
				}
			}
		}
		
		bcj[minnj] = minni;
		bzbcjbh = minni;
		bzbcj.push_back(minni);
		bzbcj.push_back(minnj);
		ans += edge[minni][jidx].money;
		/*
		printf ("%d %d %d\n", minni, minnj, ans);
		printf ("bzbcjbh:%d\n", bzbcjbh);
		*/
		
		
		while(!lt())
		{
			//printf ("into while\n");
			int minnn=inf;
			int minnni, minnnj, njidx;
			for (int i = 0; i < bzbcj.size(); i++)
			{
				//printf ("into edgei=%d\n", bzbcj[i]);
				for (int j = 0; j < edge[bzbcj[i]].size(); j++)
				{
					if (edge[bzbcj[i]][j].money < minnn && bcj[edge[bzbcj[i]][j].side] != bzbcjbh)
					{
						//printf ("min:%d %d, bcj=%d\n", bzbcj[i], edge[bzbcj[i]][j].side, bcj[edge[bzbcj[i]][j].side]);
						minnn = edge[bzbcj[i]][j].money;
						minnni = bzbcj[i];
						minnnj = edge[bzbcj[i]][j].side;
						njidx = j;
					}
				}
			}
			bcj[minnnj] = bzbcjbh;
			bzbcj.push_back(minnnj);
			ans+=edge[minnni][njidx].money;
			/*
			printf ("%d %d %d\n", minnni, minnnj, edge[minnni][njidx].money);
			printf ("bcj%dto%d\n", minnnj, bcj[minnnj]);
			printf ("lt:%d\n", lt());
			*/
		}
		printf ("%d", ans);
	}
	else 
		cout<<0;
	return 0;
}





