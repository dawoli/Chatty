#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}mp[200005];
int t,n,a[200005],maxn,b[200005],flag,c;
bool cmp(node a,node b)
{
	if(a.x==b.x)
	{
		return a.y>b.y;
	}
	else 
	{
		return a.x>b.x;
	}
}
int mian()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin >>n;
		for(int i=1;i<=n;i++)
		{
			cin >>a[i];
			mp[a[i]].x++;
			mp[a[i]].y=a[i];
		}
		if(maxn==1)
		{
			cout <<0 <<endl;
			continue;
		}
		sort(mp+1,mp+n+1,cmp);
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(j%2==1)
				{
					if(a[i]==mp[j].y)
					{
						if(b[i]==1)
						{
							continue;
						}
						b[i]=1;
						flag=1;
						mp[j].x--;
					}
					else if(flag==1 && mp[j].x!=0)
					{
						b[i]=2;
					}
				}
				else
				{
					if(a[i]==mp[j].y)
					{
						if(b[i]==2)
						{
							continue;
						}
						b[i]=1;
						flag=1;
						mp[j].x--;
					}
					else if(flag==1 && mp[j].x!=0)
					{
						b[i]=2;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if()
		}
	}
	return 0;
}
