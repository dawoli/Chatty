#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<48||ch>57) {if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
const long long N=200005;
long long T,n,a[N];
long long ans;
void work20p()
{
	for(int i=0;i<(1<<n);++i)
	{
		int lst1=0,lst0=0;
		long long sum=0;
		for(int j=1;j<=n;++j)
		   if(i&(1<<j-1))
		   {
		   	if(a[j]==lst1) sum+=a[j];
		   	lst1=a[j];
		   }
		   else
		   {
		   	if(a[j]==lst0) sum+=a[j];
		   	lst0=a[j];
		   }
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
}
long long f[200005];
long long c[200005];
long long g[200005];
void work50p()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
    for(int i=1;i<=n;++i)
    {
    	c[i-1]=0;
    	for(int j=i-2;j>=1;--j)
    	   c[j]=c[j+1]+(a[j]==a[j+1])*a[j];
    	f[i-1]=max(g[i-1]+(a[i]==a[i-1])*a[i],f[i-1]);
    	for(int j=0;j<i-1;++j)
    	{
    		f[j]=max(f[j],g[j+1]+(a[i]==a[j])*a[i]+c[j+1]);
		}
		for(int j=0;j<=i-1;++j)
		   g[i]=max(g[i],f[j]);
	}
	for(int i=1;i<n;++i) ans=max(ans,f[i]);
	cout<<ans<<"\n";
}
void work()
{
	ans=0;
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	if(n<=15)
	{
		work20p();
		return;
	}
    if(n<=20000)
    {
    	work50p();
    	return;
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	T=read();
	while(T--) work();
	return 0;
}
