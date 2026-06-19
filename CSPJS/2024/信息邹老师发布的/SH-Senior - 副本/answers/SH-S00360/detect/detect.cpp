#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100010],v[100010],a[100010],p[100010],ans,r,c[100010],o[20010][20010],b[100010],num[100010],pm[100010],maxx=-1,maxn,rr,s;
float sv,dm;
void bb()
{
	maxx=0;
	for(int j=1;j<=m;j++)
	{
		pm[j]=0;
	}
	for(int j=1;j<=n;j++)
	{
		if(b[j]==1)
		for(int k=1;k<=num[j];k++)
		{
			pm[o[j][k]]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		if(pm[j]>maxx)
		{
			maxx=pm[j];
			maxn=j;
		}
	}
	return ; 
}
void aa()
{
	int y;
	for(int x=1;x<=n;x++)
	{
		if(b[x]==1)
		{
			y=1;
			break;
		}
	}
	if(y==0)
	{
		return ;
	}
	bb();
	rr++;
	for(int x=1;x<=n;x++)
	{
		if(b[x]==1)
		for(int z=1;z<=num[x];z++)
		{
			cout<<" ";
			if(o[x][z]==maxn)
			{
				b[x]=0;
				break;
			}
		}
	}
	aa();
	return ;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		rr=0;
		maxn=0;
		maxx=-1;
		ans=0;
		r=0;
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
			num[j]=0;
			pm[j]=0;
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++)
		{
			b[j]=0;
			num[j]=0;
			pm[j]=0;
			cin>>p[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(d[j]<=p[k])
				{
					c[j]=k;
					break;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=0)
			{
				for(int k=m;k>=c[j];k--)
				{
					sv=sqrt(v[j]*v[j]+2*a[j]*(p[k]-d[j]));
					if(sv>float(V))
					{
						num[j]++;
						o[j][num[j]]=k;
						b[j]=1;
					}
					else
					{
						break;
					}
				}
				if(b[j]==1)
				{
					ans++;
				}
			}
			else
			{
				dm=v[j]*v[j]/abs(a[j])/2;
					for(int k=c[j];k<=m;k++)
					{
						if(dm+d[j]>p[k])
						{
							sv=sqrt(v[j]*v[j]+2*a[j]*(p[k]-d[j]));
						if(sv>float(V))
						{
							num[j]++;
							o[j][num[j]]=k;
							b[j]=1;
						}
						else
						{
							break;
						}
						}
						
					}
					if(b[j]==1)
					{
						ans++;
					}
			}
		}
		aa();
		r=m-rr;
		cout<<ans<<" "<<r<<endl;
	}
	return 0;
} 
