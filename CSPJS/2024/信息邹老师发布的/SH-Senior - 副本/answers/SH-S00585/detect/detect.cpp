#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans1,ans2,num[100005];
double v,l,y[100005],d[100005],v1[100005],a[100005],p[100005],c[100005],z[100005],k[10005][10005],eps=0.000000000005;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans1=ans2=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			z[i]=0;
			num[i]=0;
		} 
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v1[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			int cs=0;
			if(a[i]==0)
			{
				if(v1[i]>v)
				{
					y[i]=d[i];
					c[i]=l;
				}
				else
				{
					y[i]=d[i];
					c[i]=d[i]-1;
				}
			}
			else if(a[i]>0)
			{
				if(d[i]+(v*v-v1[i]*v1[i])/(2.0*a[i])<=l)
				{
					y[i]=max(d[i]+(v*v-v1[i]*v1[i])/(2.0*a[i]),d[i]);
					c[i]=l;
				}
				else
				{
					y[i]=d[i];
					c[i]=d[i]-1;
				}
			}
			else
			{
				y[i]=d[i];
				c[i]=d[i]+(v*v-v1[i]*v1[i])/(2.0*a[i]);
			}
			for(int j=1;j<=n;j++)
			{
				if((y[i]<=p[j]+eps)&&(p[j]<=c[i]+eps))
				{
					num[j]++;
					k[j][num[j]]=i;
					cs=1;
					z[j]++;
				}
			}
			ans1+=cs;
		}
		cout<<ans1<<" ";
		ans2=n;
		int d=0;
		int maxx=0,maxxi=0;
		while(true)
		{
			if(d==n)
			{
				cout<<ans2<<endl;
			}
			maxx=0;
			ans2--;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=num[i];j++)
				{
					if(k[i][j]==d)
					{
						if(maxx<z[i])
						{
							maxx=z[i];
							maxxi=i;
						}
						break;
					}
				}
			}
			for(int i=1;i<=num[maxxi];i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(j==maxxi)
					{
						continue;
					}
					if(z[j]==0)
					{
						continue;
					}
					for(int kk=1;kk<=num[j];kk++)
					{
						if((k[maxxi][i]==k[j][kk])&&(k[j][kk]!=0))
						{
							k[j][kk]=0;
							z[j]--;
							break;
						}
					}
				}
			}
			z[maxxi]=0;
			for(int j=1;j<=num[maxxi];j++)
			{
				if(k[maxxi][j]==d)
				{
					d++;
					break;
				}
			}
			d++;
		}
	}
	return 0;
}

