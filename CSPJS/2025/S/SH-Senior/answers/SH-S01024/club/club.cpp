#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
const int INF=2147483646;
struct node
{
	int x,y,z,pos;
}a[MAXN];
int cnt[MAXN];
bool cmpx(node p,node q)
{
	return p.x>q.x;
}
bool cmpy(node p,node q)
{
	return p.y>q.y;
}
bool cmpz(node p,node q)
{
	return p.z>q.z;
}
int tmax(int p,int q,int r)
{
	if(p>=q&&p>=r)
		return p;
	if(q>=p&&q>=r)
		return q;
	if(r>=p&&r>=q)
		return r;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int task;
	scanf("%d",&task);
	while(task--)
	{
		int n,ans=0;
		scanf("%d",&n);
		node bas[n+1]={(node){0,0,0,0}};
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			bas[i].x=a[i].x,bas[i].y=a[i].y,bas[i].z=a[i].z;
			a[i].pos=i,bas[i].pos=i;
		}
		int sumx=0,sumy=0,sumz=0,lx=0,ly=0,lz=0;
		sort(a+1,a+n+1,cmpx);
		for(int i=1;i<=n/2;++i)
		{
			cnt[a[i].pos]++;
			sumx+=a[i].x;
		}
		sort(a+1,a+n+1,cmpy);
		for(int i=1;i<=n/2;++i)
		{
			cnt[a[i].pos]++;
			sumy+=a[i].y;
		}
		sort(a+1,a+n+1,cmpz);
		for(int i=1;i<=n/2;++i)
		{
			cnt[a[i].pos]++;
			sumz+=a[i].z;
		}
		sort(a+1,a+n+1,cmpx);
		/*
		for(int i=1;i<=n;i++)
			printf("%d ",cnt[i]);
		printf("\n");
		*/
		for(int i=1;i<=n/2;++i)
			if(cnt[a[i].pos]==1)
			{
				lx++;
				sumx-=a[i].x;
				ans+=a[i].x;
				a[i].x=a[i].y=a[i].z=-1;
				bas[a[i].pos].x=bas[a[i].pos].y=bas[a[i].pos].z=-1;
			}
		sort(a+1,a+n+1,cmpy);
		for(int i=1;i<=n/2;++i)
			if(cnt[a[i].pos]==1)
			{
				ly++;
				sumy-=a[i].y;
				ans+=a[i].y;
				a[i].x=a[i].y=a[i].z=-1;
				bas[a[i].pos].x=bas[a[i].pos].y=bas[a[i].pos].z=-1;
			}
		sort(a+1,a+n+1,cmpz);
		for(int i=1;i<=n/2;++i)
			if(cnt[a[i].pos]==1)
			{
				lz++;
				sumz-=a[i].z;
				ans+=a[i].z;
				a[i].x=a[i].y=a[i].z=-1;
				bas[a[i].pos].x=bas[a[i].pos].y=bas[a[i].pos].z=-1;
			}
		sort(a+1,a+n+1,cmpx);
		for(int i=1;i<=n-lx-ly-lz;++i)
			ans+=tmax(a[i].x,a[i].y,a[i].z);
		printf("%d\n",ans);
	}
	return 0;
}
