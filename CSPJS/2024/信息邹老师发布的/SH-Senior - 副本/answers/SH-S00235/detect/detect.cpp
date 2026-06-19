#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
int d[100010];
int v[100010];
int a[100010];

int p[100010];

int f[1000010];
int g[1000010];
int f1[1000010];
int g1[1000010];
bool cmp(int x,int y)
{
	if(f1[x]!=f1[y])
	{
		return f1[x]>f1[y];
	}
	return g1[x]<g1[y];
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		
		int ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			if(v[i]<=V&&a[i]<=0)
			{
				continue;
			}
			if(v[i]>V&&a[i]>=0)
			{
				if(d[i]<=p[m])
				{
					f[d[i]]++;
					ans++;
				}
				continue;
			}
			int h1= (V*V-v[i]*v[i])/(2*a[i]);
			double h31=(V*V-v[i]*v[i])*1.0/(2*a[i]);
			if(h31-h1==0*1.0)
			{
				if(V>=v[i])h1++;
				else h1--;
				
			}
			if(V>=v[i])
			{
				if(h1<=p[m])
				{
					ans++;
					f[h1]++;
				}
			}
			if(V<v[i])
			{
				if(h1<p[1]||d[i]>p[m])continue;
				if(h1>p[m])
				{
					ans++;
					f[d[i]]++;
					g[h1]++;
					continue;
				}
				int s1=lower_bound(p+1,p+m+1,d[i])-p;
				int s2=upper_bound(p+1,p+m+1,h1)-p;
				int h21=h31;
				if(s1==s2&&h31==h21)
				{
					ans++;
					f[d[i]]++;
					g[h1]++;
				}
				if(s1!=s2)
				{
					ans++;
					f[d[i]]++;
					g[h1]++;
				}
			}
		}
		for(int i=1;i<=L;i++)
		{
			f1[i]=f1[i-1]+f[i];
			g1[i]=g1[i-1]+g[i];
		}
		sort(p+1,p+m+1,cmp);
		int cnt=1;
		int la=f1[p[1]];
		int fir=g1[p[1]];
		int minn=1e8;
		for(int i=2;i<=n;i++)
		{
			minn=min(minn,g1[p[i]]);
			if(f1[p[i]]<fir)
			{
				cnt++;
				la=f1[p[i]];
				fir=g1[p[i]];
			}
		}
		if(fir!=minn)cnt++;
		cout<<ans<<" "<<m-cnt<<endl;
	}
	return 0;
}
