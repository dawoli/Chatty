#include<bits/stdc++.h>
using namespace std;
long long T,dp[10005][600],n,p1=0,p2=0,p3=0,ans1=0,ans2=0,ans3=0;
bool sp1=true,sp2=true;
struct student{
	long long a,b,c,num,s;
}st[10001],p[10001],q[10001],r[10001];
bool cmp1(student x,student y){return x.a>y.a;}
bool cmp2(student x,student y){return x.b>y.b;}
bool cmp3(student x,student y){return x.c>y.c;}
bool cmp4(student x,student y){return x.num>y.num;}
void solve1()
{
	int ans=0;
	sort(st+1,st+n+1,cmp1);
	for(int i=1;i<=n/2;i++)
		ans+=st[i].a;
	cout<<ans<<endl;
}
int solve(int l,student m[],int size,int z)
{
	student g[size+1];int ans=0;
	memset(g,0,sizeof(g));
	if(l==1)
	{
		for(int i=1;i<=z;i++)
			g[i].num=max(m[i].b,m[i].c),g[i].s=i;
		for(int i=z+1;i<=size;i++)
			g[i].num=m[i].a,g[i].s=i;
		sort(g+1,g+1+z,cmp4);
		sort(g+2+z,g+1+size,cmp4);
		int j=size;
		for(int i=1;i<=z;i++)
		{
			while(g[i].num+g[j].num<=m[g[i].s].a&&j>=z+1)j--;
			if(j>=z+1)
			{
				ans+=g[i].num+g[j].num,j--;
			}else ans+=m[g[i].s].a;
		}
	}
	if(l==2)
	{
		for(int i=1;i<=z;i++)
			g[i].num=max(m[i].a,m[i].c),g[i].s=i;
		for(int i=z+1;i<=size;i++)
			g[i].num=m[i].b,g[i].s=i;
		sort(g+1,g+1+z,cmp4);
		sort(g+2+z,g+1+size,cmp4);
		int j=size;
		for(int i=1;i<=z;i++)
		{
			while(g[i].num+g[j].num<=m[g[i].s].b&&j>=z+1)j--;
			if(j>=z+1)
			{
				ans+=g[i].num+g[j].num,j--;
			}else ans+=m[g[i].s].b;
		}
	}
	if(l==3)
	{
		for(int i=1;i<=z;i++)
			g[i].num=max(m[i].b,m[i].a),g[i].s=i;
		for(int i=z+1;i<=size;i++)
			g[i].num=m[i].c,g[i].s=i;
		sort(g+1,g+1+z,cmp4);
		sort(g+2+z,g+1+size,cmp4);
		int j=size;
		for(int i=1;i<=z;i++)
		{
			while(g[i].num+g[j].num<=m[g[i].s].c&&j>=z+1)j--;
			if(j>=z+1)
			{
				ans+=g[i].num+g[j].num,j--;
			}else ans+=m[g[i].s].c;
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		n=0,p1=0,p2=0,p3=0,ans1=0,ans2=0,ans3=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>st[i].a>>st[i].b>>st[i].c;
			if(st[i].b!=0||st[i].c!=0)
				sp1=false;
			if(st[i].a>st[i].b&&st[i].a>st[i].c)p1++,p[p1].a=st[i].a,p[p1].b=st[i].b,p[p1].c=st[i].c,ans1+=st[i].a;
			else if(st[i].b>st[i].a&&st[i].b>st[i].c)p2++,q[p2].a=st[i].a,q[p2].b=st[i].b,q[p2].c=st[i].c,ans2+=st[i].b;
			else if(st[i].c>st[i].b&&st[i].c>st[i].a)p3++,r[p3].a=st[i].a,r[p3].b=st[i].b,r[p3].c=st[i].c,ans3+=st[i].c;
		}
		if(sp1)
		{
			solve1();
			return 0;
		}
		if(p1<=n/2)ans+=ans1;
			else ans+=solve(1,p,p1,n/2);
		if(p2<=n/2)ans+=ans2;
			else ans+=solve(2,q,p2,n/2);
		if(p3<=n/2)ans+=ans3;
			else ans+=solve(3,r,p3,n/2);
		cout<<ans<<endl;
	}
	return 0;
}
 
