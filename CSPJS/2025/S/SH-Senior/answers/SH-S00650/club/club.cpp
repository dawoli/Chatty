#include <bits/stdc++.h>
using namespace std;

int t,n,a[100005][4],ans,c[4][100005],o,p,q,minn1,minn2,minn3,ans1[6];
void add(int x,int y)
{
	if (y==1)
	{
		if (o<n/2)
		{
			ans+=a[x][y];
			c[1][++o]=x;
		}
		else
		{
			int minn=1000005,g,h;
			for (int i=1;i<=o;i++)
			{
				int e,r;
				if (a[c[1][i]][2]<a[c[1][i]][3])
				{
					e=a[c[1][i]][3];
					r=3;
				}
				else
				{
					e=a[c[1][i]][2];
					r=2;
				}
				if (a[c[1][i]][1]-e<=minn)
				{
					minn=a[c[1][i]][1]-e;
					g=r;
					h=i;
				}
			}
			if (a[x][2]<a[x][3]&&a[x][1]-a[x][3]<=minn)
			{
				add(x,3);
			}
			else if(a[x][1]-a[x][2]<=minn)
			{
				add(x,2);
			}
			else
			{
				add(c[1][h],g);
				ans-=a[c[1][h]][1];
				c[1][h]=x;
				ans+=a[x][y];
			}
		}
	}
	if (y==2)
	{
		if (p<n/2)
		{
			ans+=a[x][y];
			c[2][++p]=x;
		}
		else
		{
			int minn=1000005,g,h;
			for (int i=1;i<=p;i++)
			{
				int e,r;
				if (a[c[2][i]][1]<a[c[2][i]][3])
				{
					e=a[c[2][i]][3];
					r=3;
				}
				else
				{
					e=a[c[2][i]][1];
					r=1;
				}
				if (a[c[2][i]][2]-e<=minn)
				{
					minn=a[c[2][i]][2]-e;
					g=r;
					h=i;
				}
			}
			if (a[x][1]<a[x][3]&&a[x][2]-a[x][3]<=minn)
			{
				add(x,3);
			}
			else if(a[x][2]-a[x][1]<=minn)
			{
				add(x,1);
			}
			else
			{
				add(c[2][h],g);
				ans-=a[c[2][h]][2];
				c[2][h]=x;
				ans+=a[x][y];
			}
		}
	}
	if (y==3)
	{
		if (q<n/2)
		{
			ans+=a[x][y];
			c[3][++q]=x;
		}
		else
		{
			int minn=1000005,g,h;
			for (int i=1;i<=q;i++)
			{
				int e,r;
				if (a[c[3][i]][1]<a[c[3][i]][2])
				{
					e=a[c[3][i]][2];
					r=2;
				}
				else
				{
					e=a[c[3][i]][1];
					r=1;
				}
				if (a[c[3][i]][3]-e<=minn)
				{
					minn=a[c[3][i]][3]-e;
					g=r;
					h=i;
				}
			}
			if (a[x][1]<a[x][2]&&a[x][3]-a[x][2]<=minn)
			{
				add(x,2);
			}
			else if(a[x][3]-a[x][1]<=minn)
			{
				add(x,1);
			}
			else
			{
				add(c[3][h],g);
				ans-=a[c[3][h]][3];
				c[3][h]=x;
				ans+=a[x][y];
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		o=0,p=0,q=0;
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int x=max(a[i][1],max(a[i][2],a[i][3]));
			if (x==a[i][1])
				add(i,1);
			else if(x==a[i][2])
				add(i,2);
			else
				add(i,3);
		}
		cout<<ans<<endl;
	}
}
