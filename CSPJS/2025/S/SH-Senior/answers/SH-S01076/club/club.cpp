#include <bits/stdc++.h>
using namespace std;
int a[100005][5];
int n;
int maxn=0;
void dfs(int step,int cnt1,int cnt2,int cnt3,int sum)
{
	if (cnt1>n/2 || cnt2>n/2 || cnt3>n/2)
	{
		return ;
	}
	if (step>n)
	{
		maxn=max(maxn,sum);
		return ;
	}
	dfs(step+1,cnt1+1,cnt2,cnt3,sum+a[step][1]);
	dfs(step+1,cnt1,cnt2+1,cnt3,sum+a[step][2]);
	dfs(step+1,cnt1,cnt2,cnt3+1,sum+a[step][3]);
}
bool cmp(node x,node y)
{
	return x.p1>y.p1;
}
struct node
{
	int p1,p2,p3;
} temp[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		maxn=0;
		cin>>n;
		bool flag=true;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][2]!=0 || a[i][3]!=0)	flag=false;
		}
		if (flag)
		{
			for (int i=1;i<=n;i++)
			{
				temp[i].p1=a[i][1];
				temp[i].p2=a[i][2];
				temp[i].p3=a[i][3];
			}
			sort(temp+1,temp+n+1,cmp);
			int sum=0;
			for (int i=1;i<=n/2;i++)
			{
				sum+=temp[i].p1;
			}
			cout<<sum<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}

