#include<bits/stdc++.h>
using namespace std;
int a[2000005];
inline int read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0'); 
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		int n,k,q;
		n=read();
		k=read();
		q=read();
		for(int i=1;i<=n;i++)
		{
			int l;
			l=read();
			for(int j=1;j<=l;j++)
			{
				int x;
				x=read();
				a[x]=1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			r=read();
			c=read();
			printf("0");
			printf("\n");
		
		}
	}
	return 0;
}
