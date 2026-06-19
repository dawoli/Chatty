#include<bits/stdc++.h>
#define MAX 100001
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int t,n,m,l,vmax;
int p[MAX],d[MAX],v[MAX],a[MAX];
bool used[MAX];
bool specialA=0;
int ansspecialA=0;

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
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	while(t--)
	{
		specialA=0;
		ansspecialA=0;
		n=read();
		m=read();
		l=read();
		vmax=read();
		//printf("%d\n",vmax);
		For(i,1,n)
		{
			d[i]=read();
			v[i]=read();
			a[i]=read();
			if(a[i]!=0||specialA==1)
			{
				specialA=1;
			}
			if(v[i]>vmax)
			{
				ansspecialA++;
			}
		}
		For(i,1,m)
		{
			p[i]=read();
		}
		if(specialA==false)
		{
			if(ansspecialA==0)
			{
				printf("0 %d\n",m);
			}
			else
			{
				printf("%d %d\n",ansspecialA,m-1);
			}
			continue;
		}
	}
	return 0;
}
