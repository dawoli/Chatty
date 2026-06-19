#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,num,time=0,maxn,step;
	int n,m,l,V,ji[1001][1001],d[10001],v[10001],a[10001],p[10001],b[10001];
	float sss;
	int flag=0;
	bool fla,fl;
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		num=0;
		time=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)
			{
				sss=(V*V-v[i]*v[i])/2/a[i];
				fla=0;
				fl=0;
				for(int j=1;j<=m;j++)
				{
					if(d[i]<=p[j]&&fl==0)
					{
						flag=j;
						fl=1;
					}
				}
				for(int j=flag;j<=m;j++)
				{
					
					if(sss<p[j]-d[i])
					{
						ji[i][j]=1;
						fla=1;
						b[j]++;
					}
				}
				if(fla==1)num++;
			}
			else if(a[i]<0)
			{
				sss=(V*V-v[i]*v[i])/2/a[i];
				fla=0;
				fl=0;
				for(int j=1;j<=m;j++)
				{
					if(d[i]<=p[j]&&fl==0)
					{
						flag=j;
						fl=1;
					}
				}
				for(int j=flag;j<=m;j++)
				{
					
					if(sss>p[j]-d[i])
					{
						ji[i][j]=1;
						fla=1;b[j]++;
					}
				}
				if(fla==1)num++;
			}
			else if(a[i]==0)
			{
				fla=0;
				for(int j=1;j<=m;j++)
				{
					if(d[i]<=p[j])
					{
						flag=j;
						break;
					}
				}
				for(int j=flag;j<=m;j++)
				{
					if(v[i]>V)
					{
						ji[i][j]=1;
						fla=1;b[j]++;
					}
				}
				if(fla==1)num++;
			}
		}
		cout<<num<<" ";
		while(num>0)
		{
			maxn=0;
			for(int j=1;j<=m;j++)
			{
				if(b[j]>maxn)
				{
					maxn=b[j];
					step=j;
				}
			}
			b[step]=0;
			for(int e=1;e<=n;e++)
			{
				if(ji[e][step]==1)
				{
					num--;
					for(int f=1;f<=m;f++)
					{
						ji[e][f]=0;
					}
				}
			}
			for(int j=1;j<=m;j++)
			{
				b[j]=0;
			}
			for(int j=1;j<=m;j++)
			{
				for(int g=1;g<=n;g++)
				{
					if(ji[g][j]==1)
					{
						b[j]++;
					}
				}
			}
			time++;
		}
		cout<<m-time<<endl;
	}
	return 0;
} 
