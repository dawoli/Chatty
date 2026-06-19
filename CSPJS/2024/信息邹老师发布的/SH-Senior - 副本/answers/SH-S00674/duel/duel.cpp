#include <bits/stdc++.h>
#define lol long long
using namespace std;

struct node
{
	int id;
	lol r;
	node(){}
	node(int _id,lol _r){id = _id;r = _r;}
};
node a[100005];
long long z[100005];
bool cmp(node x,node y)
{
	return x.r < y.r;
}

lol n;
//lol r[100005];

bool vis[100005];
//表示怪物是否离场

bool vis2[100005];
//表示怪物是否具备攻击能力 

//lol z[100005];
//武力值是z的数有几个


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	bool fg = 1;
	for(int i = 1;i <= n;i ++)
	{
		lol x;
		cin>>x;
		a[i].id = i;
		a[i].r = x;
	}
	
	
	sort(a + 1,a + n + 1,cmp);
	if(a[1].r == a[n].r)
	{
		cout<<n<<'\n';
		return 0;
	}
	
	for(int i = 1;i <= n;i ++) z[a[i].r] = 1;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i].r == a[i + 1].r)
		{
			z[a[i].r] ++;
		}
	}
	
//	for(int i = 1;i <= n;i ++)
//	{
//		for(int j = 1;j <= ) 
//	}
//	
	int ans = n;
	
	for(int i = 1;i <= n;i ++)
	{
		bool flag = 0;
		//if(vis[a[i]])
		for(int j = i + 1;j <= n;j ++)
		{
			//if(a[j].r == a[j - 1].r) j += (z[a[j].r]);
			if(a[i].r < a[j].r && !vis[a[j].id] && !vis2[a[j].id])
			{
				flag = 1;
				vis[a[i].id] = 1;
				vis2[a[j].id] = 1;
				ans --;
				break;
			}
		}
		if(!flag) break;
	}
	cout<<ans<<'\n';
	return 0;
}
