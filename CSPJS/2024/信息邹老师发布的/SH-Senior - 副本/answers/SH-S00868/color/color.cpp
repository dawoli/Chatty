#include<bits/stdc++.h>
#define MAX 200001
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
struct node
{
	int number,time;
}b[MAX];
int n,t,bn=0,rn=0,ans,bmax;
int a[MAX];
bool color[MAX],temp,v[MAX];
priority_queue<int> pq;

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

bool cmp(node a,node b)
{
	return a.time>b.time;
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		ans=0;
		bn=0;
		rn=0;
		For(i,1,n)
		{
			a[i]=read();
			b[a[i]].time++;
			b[a[i]].number=a[i];
			if(!v[a[i]])
			{
				bmax++;
				v[a[i]]=1;
			}
		}
		sort(b+1,b+bmax+1,cmp);
		For(i,1,bmax)
		{
			color[i]=temp;
			temp=!temp;
		}
		For(i,1,n)
		{
			if(color[a[i]]==0)
			{
				if(a[i]==a[bn])
				{
					ans+=a[i];
				}
				bn=i;
			}
			else
			{
				if(a[i]==a[rn])
				{
					ans+=a[i];
				}
				rn=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
