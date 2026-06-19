#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,fa,fb,fc,ans,p[100010][2];
double v;
struct car
{
	double d,v,a;
	int flag=0,l,r;
}c[100010];
int chk(int l,int r)
{
	for(int i=1;i<=m;i++)
	{
//		cout<<l<<" "<<r<<" "<<i<<endl;
		if(p[i][1]==0 && p[i][0]<=r && p[i][0]>=l)
			return 1;
		if(p[i][0]>r)
			return 0;
	}
	return 0;
}
int dfs(int now,int cnt)
{
	if(now>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i].flag==0)
				continue;
			if(chk(c[i].l,c[i].r)==0)
				return 0;
//			cout<<cnt<<endl;
			ans=min(ans,cnt);
		}
		return 0;
	}
	p[now][1]=0;
	dfs(now+1,cnt+1);
	p[now][1]=1;
	dfs(now+1,cnt);
	p[now][1]=0;
	return 0;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%lf",&n,&m,&l,&v);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&c[i].d,&c[i].v,&c[i].a);
			if(c[i].a!=0)
				fa=1;
			if(c[i].a>=0)
				fc=1;
			if(c[i].a<=0)
				fb=1; 
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&p[i][0]);
		}
		if(fa==0)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i].v>v && c[i].d<=p[m][0])
					ans++;
			}
			printf("%d %d\n",ans,ans==0?m:m-1);
			continue;
		}
		if(fb==0)
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
//				cout<<v<<" "<<c[i].v<<" "<<(v*v-c[i].v*c[i].v)/2/c[i].a<<endl;
				if(c[i].d<=p[m][0] && c[i].d+(v*v-c[i].v*c[i].v)/2/c[i].a<p[m][0])
					ans++;
			}
			printf("%d %d\n",ans,ans==0?m:m-1);
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i].a==0)
			{
				if(c[i].v>v && c[i].d<=p[m][0])
				{
					c[i].flag=1;
					c[i].l=c[i].d;
					c[i].r=l;
					ans++;
				}
				else
					c[i].flag=0;
			}
			if(c[i].a>0)
			{
				if(c[i].d<=p[m][0] && c[i].d+(v*v-c[i].v*c[i].v)/2/c[i].a<=p[m][0])
				{
					c[i].flag=1;
					c[i].l=c[i].d+(v*v-c[i].v*c[i].v)/2/c[i].a;
					c[i].r=l;
					ans++;
				}
				else
					c[i].flag=0;
			}
			if(c[i].a<0)
			{
				if(chk(c[i].d,c[i].d+(v*v-c[i].v*c[i].v)/2/c[i].a))
				{
					c[i].flag=1;
					c[i].l=c[i].d;
					c[i].r=c[i].d+(v*v-c[i].v*c[i].v)/2/c[i].a;
					ans++;
				}
				else
					c[i].flag=0;
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<c[i].l<<" "<<c[i].r<<endl;
//		}
		printf("%d ",ans);
		ans=m;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
