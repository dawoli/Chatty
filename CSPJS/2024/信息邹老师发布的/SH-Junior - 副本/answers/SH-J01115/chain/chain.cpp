#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
int n,m,k,q,mr,p[N],mp[N],r[N],c[N];
int f[N][102];
vector<int> a[N];
int read()
{
	int f=0,x=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')x=-1;c=getchar();}
	while(isdigit(c)){f=f*10+(c^48);c=getchar();}
	return x*f;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T=read();
	while(T--)
	{
		m=0;
		n=read(),k=read(),q=read();
		int u,v;
		for(int i=1;i<=n;i++)
		{
			u=read();
			a[i].clear();
			for(int j=1;j<=u;j++)
			{
				v=read();
				a[i].push_back(v);
				p[++m]=v;
			}
		}
		sort(p+1,p+1+m);
		m=unique(p+1,p+1+m)-p-1;
		for(int i=1;i<=m;i++)
			mp[p[i]]=i;
		for(int i=1;i<=n;i++)
			for(int j=0;j<a[i].size();j++)
				a[i][j]=mp[a[i][j]];
		mr=0;
		for(int i=1;i<=q;i++)
			r[i]=read(),c[i]=read(),mr=max(mr,r[i]);
		for(int i=1;i<=m;i++)
			for(int j=0;j<=mr;j++)
				f[i][j]=-1;
		f[mp[1]][0]=0;			
		for(int t=1;t<=mr;t++)
		{
			for(int i=1;i<=n;i++)
			{
				int r=a[i].size();
				for(int u=a[i].size()-1;u>=0;u--)
				{
					int cu=a[i][u];
					if(f[cu][t-1]==-1||f[cu][t-1]==i)
						continue;
					for(int v=u+1;v<min(u+k,r);v++)
					{
						int cv=a[i][v];
						f[cv][t]=(f[cv][t]==-1?i:(f[cv][t]==i?i:0));
					}
					r=u+1;
				}
			}
				
		}
		for(int i=1;i<=q;i++)
			printf("%d\n",(f[mp[c[i]]][r[i]]!=-1));
	}
	
}
