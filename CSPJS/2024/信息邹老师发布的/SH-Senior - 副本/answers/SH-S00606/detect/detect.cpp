#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100005],v[100005],a[100005],p[100005],ans1,ans2,b[100005][2],x,minn,maxn,minn1;//flag[100005][100005],y[100005],e[100005],f;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	
	for (int u=1;u<=t;u++)
	{
		/*
		for (int i=1;i<=x;i++)
		{
			for (int j=0;j<=m;i++)
			{
				flag[i][j]=0;
			}
		}
		x=0;
		*/
		cin>>n>>m>>l>>V;
		for (int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for (int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				if (v[i]>=V&&d[i]<=p[m])
				{
					b[++x][0]=1;
					b[x][1]=i;
					ans1++;
					ans2=1;
					for(int j=1;j<=m;j++)
					{
						if (p[j]>=d[i])
						{
							minn1=max(minn1,p[j]);
						}
					}
				}
			}
			if (a[i]>0)
			{
				for(int j=1;j<=m;j++)
				{
					if (sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V)
					{
						b[++x][0]=j;
						b[x][1]=i;
						ans1++;
						ans2=1;
						break;
						minn1=max(minn1,p[j]);
					}
				}
			}
			if (a[i]<0)
			{
				for (int j=m;j>=1;j--)
				{
					if (v[i]*v[i]+2*a[i]*(p[j]-d[i]<0))
						break;
					if (sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V)
					{
						b[++x][0]=-j;
						b[x][1]=i;
						ans1++;
						/*
						if (d[i]<minn)
						{
							minn=d[i];
							ans2++;
						}
						if(minn==0)
						{
							minn=b[x][i];
						}
						if (p[j]<minn1)
						{
							minn1=p[j];
							ans2++;
						}
						if(d[i]>maxn)
						{
							maxn=d[i];
							ans2++;
						}*/
						break;
					}
				}
			}
		}
		/*
		for (int i=1;i<=m;i++)
		{
			y[i]=0;
			for (int j=1;j<=x;j++)
			{
				if (b[j][0]<0)
				{
					if(i<=b[j][0])
					{
						flag[i][0]++;
						flag[i][++y[i]]=b[j][1];
						e[b[j][1]]++;
					}
				}
				else if (b[j][0]==0)
				{
					flag[i][0]++;
					flag[i][++y[i]]=b[j][1];
					e[b[j][1]]++;
				}
				else
				{
					if (i>=b[j][0])
					{
						flag[i][0]++;
						flag[i][++y[i]]=b[j][1];
						e[b[j][1]]++;
					}
				}
			}
		}
		for (int i=1;i<=m;i++)
		{
			f=1;
			for (int j=1;j<=y[i];j++)
			{
				if (e[flag[i][j]]==1&&f==1)
				{
					ans2++;
					f=0;
				}
				flag[i][j]--;
			}
		}
		*/
		cout<<ans1<<" "<<n-ans2<<endl;
	}
	return 0;
}
