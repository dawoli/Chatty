#include<bits/stdc++.h>

using namespace std;

int plan[200500];

int t,n;

int a[200500];

int maxn = 0;

int l1,l2;

int vis[1000050];

int vst[1000050];

int la[1000050];

int work()
{
	int res = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = i-1;j >= 1;j--)
		{
			if(plan[i] == plan[j])
			{
				if(a[j] == a[i])
				{
					res+=a[i];
				}
				break;
			}
		}
	}
	return res;
}

void dfs(int step)
{
	if(step > n)
	{
		maxn = max(maxn,work());
		return ;
	}
	plan[step] = 1;
	dfs(step+1);
	plan[step] = 0;
	dfs(step+1);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n <= 15)
		{
			for(int i = 1;i <= n;i++)
			{
				cin>>a[i];
			}
			maxn = 0;
			memset(plan,0,sizeof(plan));
			dfs(1);
			cout<<maxn<<"\n";
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			cin>>a[i];
			vis[a[i]]++;
		}
		int last = 0;
		for(int i = 1;i <= n;i++)
		{
			if(vis[a[i]] == 1)
			{
				if(l1 == l2 && l1 == 0)
				{
					plan[i] = last;
					continue;
				}
				if(a[l1] > a[l2])
				{
					plan[i] = (la[a[l1]]+1)%2;
				}
				else
				{
					plan[i] = (la[a[l2]]+1)%2;
				}
			}
			else
			{
				if(vst[a[i]] > 0)
				{
					plan[i] = la[a[i]];
					continue;
				}
				last++;
				plan[i] = (last)%2;
				la[a[i]] = plan[i];
				vst[a[i]]++;
				l1 = l2;
				l2 = i;
			}
		}
		cout<<work()<<"\n";
	}
	return 0;
} 
