#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int t,a[30][5],n[30],m[30];
double d[100010],vchu[100010],jia[100010],x[100010],le[100010],r[100010],l[30],v[30];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		cin>>n[i]>>m[i]>>l[i]>>v[i];
		int sum=0;
		for(int j=1;j<=n[i];j++)
		{
			cin>>d[j]>>vchu[j]>>jia[j];
		}
		for(int j=1;j<=m[i];j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=n[i];j++)
		{
			if(vchu[j]>v[i]&&jia[j]>=0)
			{
				for(int k=1;k<=m[i];k++)
				{
					if(x[k]>=d[j])
					{
						ans++;
						le[j]=k;
						r[j]=m[i];
						break;
					}
				}
			}
			else if(vchu[j]==v[i]&&jia[j]>0)
			{
				for(int k=1;k<=m[i];k++)
				{
					if(x[k]>d[j])
					{
						ans++;
						le[j]=k;
						r[j]=m[i];
						break;
					}
				}
			}
			else if(vchu[j]<v[i]&&jia[j]>0)
			{
				double t1=(v[i]-vchu[j])/jia[j];
				for(int k=1;k<=m[i];k++)
				{
					if(x[k]>(vchu[j]+v[i])*t1/2+d[j])
					{
						ans++;
						le[j]=k;
						r[j]=m[i];
						break;
					}
				}
			}
			else if(vchu[j]>v[i]&&jia[j]<0)
			{
				double t1=(vchu[j]-v[i])/jia[j];
				t1=-t1;
				for(int k=1;k<=m[i];k++)
				{
					if(((vchu[j]+v[i])*t1/2+d[j]>l[i])&&(x[k]>=d[j]&&x[k]<=l[i]))
					{
						ans++;
						le[j]=k;
						break;
					}
					else if((x[k]>=d[j]&&x[k]<(vchu[j]+v[i])*t1/2+d[j])&&((vchu[j]+v[i])*t1/2+d[j]<l[i]))
					{
						ans++;
						le[j]=k;
						break;
					}
				}
				if((vchu[j]+v[i])*t1/2+d[j]>l[i])
				{
					r[j]=m[i];
				}
				else
				{
					for(int k=1;k<=m[i];k++)
					{
						if(x[k]>=(vchu[j]+v[i])*t1/2+d[j])
						{
							r[j]=k-1;
							break;
						}
					}
					if(r[j]==0)
					{
						r[j]=m[i];
					}
				}
			}
		}
		a[i][1]=ans;
		for(int j=1;j<=m[i];j++)
		{
			bool flag=0;
			for(int k=1;k<=n[i];k++)
			{
				if(le[k]==j&&le[k]==r[k])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				for(int k=1;k<=n[i];k++)
				{
					if(le[k]==j)
					{
						le[k]++;
					}
				}
				sum++;
			}
		}
		a[i][2]=sum;
		for(int j=1;j<=n[i];j++)
		{
			le[j]=0;
			r[j]=0;
		}
	}
	for(int i=1;i<=t;i++)
	{
		cout<<a[i][1]<<" "<<a[i][2]<<endl;
	}
	return 0;
}
