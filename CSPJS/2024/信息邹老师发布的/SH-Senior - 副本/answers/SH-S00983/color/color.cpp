#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int a[M];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		long long ans=0;
		int r0=-1,rl=-1;
		int f[M]={0},co[M]={0};
		queue <int> q;
		int c0=-1,c1,ocp=0;
		for(int i=0;i<n;i++)
		{
			q.push(a[i]);
			if(a[i]==c0)ocp=0;
			if(f[a[i]])
			{
				while(!q.empty())
				{
					if(f[q.front()]==1)
					{
						if(ocp)c0=f[q.front()];
						else c1=f[q.front()];
						q.pop();
					}
					else if(f[q.front()]!=1)
					{
						if(c0==q.front())
						{
							c0=q.front();
							ocp=0;
							ans+=q.front();
						}
						else if(c1==q.front())
						{
							c1=q.front();
							ocp=1;
							ans+=q.front();
						}
						else
						{
							c0=q.front();
							ocp=0;
						}
						q.pop();
					}
				}
			}
			else
			{
				f[q.front()]++;
			}
		}
		cout<<ans;
	}
	return 0;
}
