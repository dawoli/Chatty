#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+7;
int a[N],c[N],d[257][4];
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
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	
	return 0;
}
