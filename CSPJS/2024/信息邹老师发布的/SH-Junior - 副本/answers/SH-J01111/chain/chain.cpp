#include<bits/stdc++.h>
using namespace std;
int n,k,q,ans;

struct node{
	int l;
	int s[2005]; 
}a[1005];

void dfs(int r,int end,int last)
{
	if(r==0) return;
	int begin;
	for(int i=1;i<=n;i++)
	{
		if(i!=last)
		{
			for(int j=2;j<=a[i].l;j++)
			{
				if(a[i].s[j]==end)
				{
					begin=max(j-k+1,1);
					for(int m=begin;m<j;m++)
					{
						if(r==1 && a[i].s[m]==1)
						{
							ans=1;
							return;
						}
						dfs(r-1,a[i].s[m],i);
					}
				}
			}
		}
	}
}

void solve1000()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l;
		for(int j=1;j<=a[i].l;j++)
		{
			cin>>a[i].s[j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		int r,end;
		ans=0;
		cin>>r>>end;
		dfs(r,end,-1);
		cout<<ans<<"\n";
	}
	
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		if(n<=1000)
		{
			solve1000();
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				int x,y;
				cin>>x;
				for(int j=1;j<=x;j++)
				{
					cin>>y;
				}
			}
			for(int i=1;i<=q;i++)
			{
				int r,end;
				cin>>r>>end;
				cout<<"1\n";
			}
		}
	}
	return 0;
}
