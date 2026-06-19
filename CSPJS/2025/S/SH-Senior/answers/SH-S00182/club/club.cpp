#include<bits/stdc++.h>
using namespace std;
int t,d,e,a,b,pos; //d为人数
int member[4][20000];
int sum[5][20000]; //分数统计数组 
struct num
{
	int a;
	int b;
	int c;
}n[4][20000]; //人数统计数组 
int ans;
void dfs(int sta)
{
	if(sta==d+1)
	{
		ans=max(ans,sum[1][d]);
		ans=max(ans,sum[2][d]);
		ans=max(ans,sum[3][d]);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(j==1) 
			{
				n[j][sta].a=n[i][sta-1].a+1;
				n[j][sta].b=n[i][sta-1].b;
				n[j][sta].c=n[i][sta-1].c;
			}
			if(j==2) 
			{
				n[j][sta].a=n[i][sta-1].a;
				n[j][sta].b=n[i][sta-1].b+1;
				n[j][sta].c=n[i][sta-1].c;
			}
			if(j==3) 
			{
				n[j][sta].a=n[i][sta-1].a;
				n[j][sta].b=n[i][sta-1].b;
				n[j][sta].c=n[i][sta-1].c+1;
			}
			if(n[j][sta].a>e || n[j][sta].b>e || n[j][sta].c>e)
			{
				return;
			}
			sum[j][sta]=sum[i][sta-1]+member[j][sta];
			dfs(sta+1);
			n[j][sta].a=0;
			n[j][sta].b=0;
			n[j][sta].c=0;
			sum[j][sta]=0;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		ans=0;
		memset(sum,0,sizeof(sum));
		memset(member,0,sizeof(member));
		cin>>d;
		for(int i=1;i<=d;i++)
		{
			cin>>member[1][i]>>member[2][i]>>member[3][i];
		}
		e=d/2;
		if (d<=200)
		{
			dfs(1);
			cout<<ans<<"\n";
		}
		else{
			for(int i=1;i<=d;i++)
			{
				if(a<member[2][i] && member[1][i]==0) 
				{
					a=member[2][i];
					pos=i;
				}
			}
			member[1][pos]=1;
			for(int i=1;i<=d;i++)
			{
				if(b<member[2][i] && member[1][i]==0) 
				{
					b=member[2][i];
					pos=i;
				}
			}
			cout<<a+b<<"\n";
		}
	}
	return 0;
}
