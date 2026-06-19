#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define MAX 100001
using namespace std;
int n,ans,kind=1,type;
int a[MAX],b[MAX],attack[MAX];

inline int read()
{
	char c=getchar();
	int k=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=ans=read();
	For(i,1,n)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	type=a[1];
	For(i,1,n)
	{
		if(type!=a[i])
		{
			kind++;
			type=a[i];
		}
		b[kind]++;
		attack[kind]=b[kind];
	}
	For(i,1,kind)
	{
		if(b[i]==0)
		{
			continue;
		}
		For(j,i+1,kind)
		{
			if(b[i]<=attack[j])
			{
				ans-=b[i];
				attack[j]-=b[i];
				attack[i]=0;
				b[i]=0;
			}
			else
			{
				ans-=attack[j];
				b[i]-=attack[j];
				attack[i]-=attack[j];
				attack[j]=0;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
