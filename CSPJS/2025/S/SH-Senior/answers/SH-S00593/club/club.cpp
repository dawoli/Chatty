#include <bits/stdc++.h>
using namespace std;
const int N=100005;
typedef struct node
{
	int a,b,c;
}NODE;
NODE a[N],b[N],c[N];
int al,bl,cl;
bool cmpa(NODE x,NODE y)
{
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmpb(NODE x,NODE y)
{
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmpc(NODE x,NODE y)
{
	return min(x.c-x.b,x.c-x.a)<min(y.c-y.b,y.c-y.a);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int x,y,z,n,ans=0;
		al=bl=cl=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			int maxv=max(x,max(y,z));
			if(x==maxv) a[++al]=NODE{x,y,z},ans+=x;
			else if(y==maxv) b[++bl]=NODE{x,y,z},ans+=y;
			else if(z==maxv) c[++cl]=NODE{x,y,z},ans+=z;
		}
		if(al>n/2)
		{
			sort(a+1,a+1+al,cmpa);
			for(int i=1;i<=al-n/2;i++)
				ans-=min(a[i].a-a[i].b,a[i].a-a[i].c);
		}
		if(bl>n/2)
		{
			sort(b+1,b+1+bl,cmpb);
			for(int i=1;i<=bl-n/2;i++)
				ans-=min(b[i].b-b[i].a,b[i].b-b[i].c);
		}
		if(cl>n/2)
		{
			sort(c+1,c+1+cl,cmpc);
			for(int i=1;i<=cl-n/2;i++)
				ans-=min(c[i].c-c[i].b,c[i].c-c[i].a);
		}
		printf("%d\n",ans);
	}
	return 0;
}
