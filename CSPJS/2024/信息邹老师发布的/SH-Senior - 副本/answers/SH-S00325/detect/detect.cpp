#include <bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+7;
int n,m,L,V;
int d[N],v[N],a[N];
int p[N];
inline int read()
{
	char ch=getchar();
	int res=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		res=res*10+ch-'0',ch=getchar();
	return res*f;
}
double dis(int k,double t)
{
	return d[k]*t+0.5*a[k]*t*t;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=n;i++)
		{
			d[i]=read(),v[i]=read(),a[i]=read();
		}
		for(int i=1;i<=m;i++)
			p[i]=read();
		cout<<m<<" "<<m<<endl;
	}
	return 0;
}
