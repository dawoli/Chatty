#include<bits/stdc++.h>
using namespace std;
const int N=20002;
int t,n,m,l,v0,boo[N],f[N][N];
int d[N],v[N],a[N],p[N];
int g[N],tr[N];
void check(int ti,long long v1,int j)
{
	for(int i=1;i<=n;i++)
	{
		if(d[i]>ti)  continue;
		long long o1=(v[i]*v[i])+2*a[i]*(t-d[i]);
		if(o1>v1)  
		{
			boo[i]=1;
			f[i][j]=1;
			g[j]++;
		}
	}
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>l>>v0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(boo,0,sizeof(boo));
		memset(tr,0,sizeof(t));
		long long v1=v0*v0;
		int y=0;
		for(int j=1;j<=n;j++) 
		{
			cin>>d[j]>>v[j]>>a[j];
			if(a[j]!=0)  y=1;
			boo[j]=0;
		 } 
		for(int j=1;j<=m;j++)  
		{
			cin>>p[j];
		}
		if(y==0)
		{
			int s=0;
			for(int j=1;j<=n;j++)
			{
				if(v[j]>v0 and d[j]<=p[m])  s++;
			}
			int s1=m-1;
			cout<<s<<" "<<s1<<endl;
			continue;
		}
		for(int j=1;j<=m;j++)  
		{
			check(p[j],v1,j);
		}
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			if(boo[j]==1)  sum++;
		}
		cout<<sum<<" ";
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(tr[j]==0 and boo[j]==1)
			{
			    ans++;
				int max=-1,ma=0;
				for(int k=1;k<=m;k++)
				{
					if(g[k]>max)  
					{
						max=g[k];
						ma=k;	
					}
				}
				for(int le=1;le<=n;le++)
				{
					if(f[le][ma]==1)  tr[le]=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
