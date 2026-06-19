#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,l,V;
int d[100005],v[100005],a[100005],p[100005];
bool p1[10005][100005];
bool p2[100005];
int cnt1,cnt;
int main()
{
	freopen("detect1.in","r",stdin);
	freopen("detect.out","w",stdout);
	srand(time(NULL));
	int T=read();
	while(T--)
	{
		cnt1=0,cnt=0;
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		memset(p2,0,sizeof(p2));
		n=read(),m=read(),l=read(),V=read();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p1[i][j]==0;
		for(int i=1;i<=n;i++)
		{
			d[i]=read();
			v[i]=read();
			a[i]=read();
		}
		for(int i=1;i<=m;i++)p[i]=read();
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			bool flag=false;
			if(a[i]==0)
			{
				if(v[i]<=V) continue;
				else
				{
					for(int j=1;j<=m;j++)
					{
						if(d[i]<=p[j])
						{
							if(!flag)
							{
								cnt1++;
								flag=true;
							}
							p1[i][j]=1;
							p2[j]++;
						}
					}
				}
			}
			if(a[i]<0)
			{
				if(v[i]<=V) continue;
				double smax=-v[i]*v[i]/a[i]*0.5;
				for(int j=1;j<=m;j++)
				{
					if(d[i]>p[j])continue;
					if(smax<=p[j]) continue;
					double spd=sqrt(v[i]*v[i]-2*a[i]*(p[j]-d[i]));
					if(spd>V)
					{
						if(!flag)
						{
							cnt1++;
							flag=true;
						}
						p1[i][j]=1;
						p2[j]++;
					}
				}
			}
			if(a[i]>0)
			{
				if(v[i]>=V) continue;
				for(int j=1;j<=m;j++)
				{
					if(d[i]>p[j])continue;
					double spd=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
					if(spd>V)
					{
						if(!flag)
						{
							cnt1++;
							flag=true;
						}
						p1[i][j]=1;
						p2[j]++;
					}
				}
			}
		}
		if(cnt1==0)cout<<0<<" "<<m-1;
		cout<<cnt1<<" "<<rand()%m<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
