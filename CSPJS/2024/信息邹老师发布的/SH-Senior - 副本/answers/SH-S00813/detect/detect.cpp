#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int T,n,m,L,V,ans1,ans2;
struct car
{
	int d,v,a,l,r;
	bool b;
};
car c[100001];
int p[100001];
int t[100001],b[100001];
void deal(int i)
{
	if(c[i].v<=V&&c[i].a<=0) c[i].b=false;
	if(c[i].v>V&&c[i].a<0)
	{
		c[i].b=true;
		int x=c[i].v*c[i].v-V*V;
		c[i].l=c[i].d;
		c[i].r=c[i].d+x/(-2*c[i].a);
		if(x%(2*c[i].a)==0) c[i].r--;
	}
	if(c[i].v>V&&c[i].a>=0)
	{
		c[i].b=true;
		c[i].l=c[i].d;
		c[i].r=L;
		if(c[i].v==V) c[i].l++;
	}
	if(c[i].v<=V&&c[i].a>0)
	{
		c[i].b=true;
		int x=V*V-c[i].v*c[i].v;
		c[i].l=c[i].d+x/(2*c[i].a);
		c[i].r=L;
		if(x%(2*c[i].a)==0) c[i].l++;
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	for(int j=0;j<T;j++)
	{
		scanf("%d%d%d%d",&m,&n,&L,&V);
		ans1=0;
		ans2=0;
		int i=0;
		t[0]=1;
		b[0]=n-1;
		for(i=1;i<n;i++)
		{
			t[i]=i+1;
			b[i]=i-1;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
			deal(i);
		}
		for(i=0;i<m;i++) scanf("%d",&p[i]);
		i=0;
		while(i<n)
		{
			if(c[i].b==false)
			{
				if(i!=0)
				{
					t[b[i]]=t[i];
					b[t[i]]=b[i];
				}
				i=t[i];
				continue;
			}
			int l=0,r=m-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(p[mid]<c[i].l) l=mid+1;
				if(p[mid]>c[i].r) r=mid;
				if(p[mid]>=c[i].l&&p[mid]<=c[i].r)
				{
					l=mid;
					break;
				}
			}
			if(p[l]>=c[i].l&&p[l]<=c[i].r) ans1++;
			else
			{
				if(i!=0)
				{
					t[b[i]]=t[i];
					b[t[i]]=b[i];
				}
			}
			i=t[i];
		}
		i=0;
		while(i<n)
		{
			int l=0,r=m-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(p[mid]<c[i].l) l=mid+1;
				if(p[mid]>c[i].l) r=mid;
				if(p[mid]==c[i].l)
				{
					l=mid;
					break;
				}
			}
			c[i].l=l;
			l=0;
			r=m-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(p[mid]<c[i].r) l=mid+1;
				if(p[mid]>c[i].r) r=mid;
				if(p[mid]==c[i].r)
				{
					r=mid+1;
					break;
				}
			}
			c[i].r=r-1;
			i=t[i];
		}
		i=0;
		int num=0;
		while(num<n)
		{
			while(i<n)
			{
				if(c[i].b==false)
				{
					i=t[i];
					continue;
				}
				int k=t[i];
				while(k<n)
				{
					int l=max(c[i].l,c[k].l),r=min(c[i].r,c[k].r);
					if(l<=r)
					{
						c[i].l=l;
						c[i].r=r;
						t[b[k]]=t[k];
						b[t[k]]=b[k];
					}
					k=t[k];
				}
				i=t[i];
			}
			num=t[num];
		}
		i=0;
		while(i<n)
		{
			if(c[i].b==true) ans2++;
			i=t[i];
		}
		ans2=m-ans2;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
