#include<bits/stdc++.h>
using namespace std;
int T, n, a[100005][2], ans=0;
void bfs(int p)
{
	if(p==n+1)
	{
		int sum=0, r=0, b=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1])
			{
				if(!r)
					r=a[i][0];
				else
				{
					if(a[i][0]==r)
						sum+=a[i][0];
					else
						r=a[i][0];
				}
			}
			if(!a[i][1])
			{
				if(!b)
					b=a[i][0];
				else
				{
					if(a[i][0]==b)
						sum+=a[i][0];
					else
						b=a[i][0];
				}
			}
		}
		ans=max(ans,sum);
		return ;
	}
	a[p][1]=0;
	bfs(p+1);
	a[p][1]=1;
	bfs(p+1);
}
void work()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0];
	ans=0;
	bfs(1);
	cout<<ans<<"\n";
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
		work();
	return 0;
}
