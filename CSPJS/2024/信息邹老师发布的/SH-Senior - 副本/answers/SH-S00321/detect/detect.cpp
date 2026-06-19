#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
struct Car
{
	int d,v,vj;
	double l,r;
}a[1000006];
int p[1000006];
int use[1000006];
bool isuse[1000006];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int ans1=0,ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d>>a[i].v>>a[i].vj;
			if(a[i].vj==0)
			{
				if(a[i].v>V)
				{
					a[i].l=a[i].d;
				    a[i].r=L;
				}
				else
				{
					a[i].l=0;
					a[i].r=-1;
				}
			}
			else if(a[i].vj>0)
			{
				a[i].l=a[i].d+ceil((V*V-a[i].v*a[i].v)/(2*a[i].vj))+0.5;
				a[i].r=L;
			}
			else
			{
				if(a[i].v>V)
				{
					a[i].l=a[i].d;
					a[i].r=a[i].d+floor((V*V-a[i].v*a[i].v)/(2*a[i].vj));
				}
				else
				{
					a[i].l=0;
					a[i].r=-1;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			int f=0;
			for(int j=1;j<=m;j++)
		    {
		        if(a[i].l<=p[j] && a[i].r>=p[j] && f==0)
		        {
		    	    ans1++;
		    	    f=1;
		    	}
		    	if(a[i].l<=p[j] && a[i].r>=p[j])
		        {
		        	use[j]++;
		        }
		    }
		}
		for(int i=1;i<=n;i++)
		{
			queue<int>q;
			for(int j=1;j<=m;j++)
		    {
		        if(a[i].l<=p[j] && a[i].r>=p[j])
		        {
		    	    q.push(j);
		    	}
		    }
		    int mx=-1,mxi=-1;
		    while(!q.empty())
		    {
		    	int i=q.front();
		    	q.pop();
		    	if(mx<use[i])
		    	{
		    		mx=use[i];
		    		mxi=i;
				}
			}
			isuse[mxi]=1;
		}
		for(int i=1;i<=m;i++)if(isuse[i]==0)
		{
			ans2++;
		}
		cout<<ans1<<' '<<ans2<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
