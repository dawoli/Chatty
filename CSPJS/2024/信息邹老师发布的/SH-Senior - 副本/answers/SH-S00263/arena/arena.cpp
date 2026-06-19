#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
long long a[10005],c[10005];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	long long n,m,k=1;
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) c[m]=read();
	for(int i=1;i<=n;i++)
	{
		k*=2;
		if(k>=n)
		{
			k=i;
			break;
		}
	}
	for(int i=1;i<=k;i++) c[i]=read();
	long long T;
	T=read();
	while(T--)
	{
		srand(time(0));
		long long ans;
		ans=rand();
		write(ans);
	}
	return 0;
}
