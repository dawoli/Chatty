#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans,b[100005],man[4];
struct node
{
	int a1,a2,a3;
};
void dfs1(int now)
{
	if(now==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1)sum+=a[i][1];
			if(b[i]==2)sum+=a[i][2];
			if(b[i]==3)sum+=a[i][3];
		}
		ans=max(ans,sum);
	}
	for(int i=1;i<=3;i++)
	{
		if(man[i]==(n/2))continue;
		man[i]++;
		b[now]=i;
		dfs1(now+1);
		b[now]=0;
		man[i]--;
	}
	return;
}
bool cmp1(node a,node b)
{
	if(a.a1==b.a1)
	{
		if(a.a2==b.a2)return a.a3>b.a3;
		return a.a2>b.a2;
	}
	return a.a1>b.a1;
}
void solve()
{
	scanf("%d",&n);
	ans=0;
	man[1]=man[2]=man[3]=man[4]=0;
	bool flag1=1,flag2=1,flag3=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][2]!=0||a[i][3]!=0)flag1=0;
		if(a[i][1]!=0||a[i][3]!=0)flag2=0;
		if(a[i][1]!=0||a[i][2]!=0)flag3=0;
	}
	if(n==2)
	{
		//cout<<"n"<<endl;
		ans=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				if(i==j)continue;
				ans=max(ans,a[1][i]+a[2][j]);
			}
		printf("%d\n",ans);
		return;
	}
	if(flag1)
	{
		//cout<<"flag1"<<endl;
		for(int i=1;i<=n;i++)b[i]=a[i][1];
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)ans+=a[i][1];
		printf("%d\n",ans);
		return;
	}
	if(flag2)
	{
		//cout<<"flag2"<<endl;
		for(int i=1;i<=n;i++)b[i]=a[i][2];
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)ans+=a[i][2];
		printf("%d\n",ans);
		return;
	}
	if(flag3)
	{
		//cout<<"flag3"<<endl;
		for(int i=1;i<=n;i++)b[i]=a[i][3];
		sort(b+1,b+1+n);
		for(int i=n;i>n/2;i--)ans+=a[i][3];
		printf("%d\n",ans);
		return;
	}
	if(n<=10)
	{
		dfs1(1);
		printf("%d\n",ans);
		return;
	}
	vector<node> c;
	for(int i=1;i<=n;i++)
	{
		c.push_back({a[i][1],a[i][2],a[i][3]});
	}
	sort(c.begin(),c.end(),cmp1);
	for(int i=1;i<=n/2;i++)ans+=c[i].a1;
	for(int i=n/2+1;i<=n;i++)ans+=c[i].a2;
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
