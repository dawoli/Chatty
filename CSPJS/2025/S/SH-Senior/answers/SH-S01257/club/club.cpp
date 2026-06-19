#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,f1=1,f2=1;
priority_queue<int> q;
struct stu{
	long long z1,z2,z3;
	long long cha;
}a[100005];
bool cmp1(stu x,stu y)
{
	return x.z1>=y.z1;
}
bool cmp2(stu x,stu y)
{
	return x.cha>=y.cha;
}
void dfs(int pos,int cnt1,int cnt2,int cnt3,long long sum)
{
	if(pos==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(cnt1==n/2)
	{
		dfs(pos+1,cnt1,cnt2+1,cnt3,sum+a[pos].z2);
		dfs(pos+1,cnt1,cnt2,cnt3+1,sum+a[pos].z3);
	}
	else dfs(pos+1,cnt1+1,cnt2,cnt3,sum+a[pos].z1);
	if(cnt2==n/2)
	{
		dfs(pos+1,cnt1+1,cnt2,cnt3,sum+a[pos].z1);
		dfs(pos+1,cnt1,cnt2,cnt3+1,sum+a[pos].z3);
	}
	else dfs(pos+1,cnt1,cnt2+1,cnt3,sum+a[pos].z2);
	if(cnt3==n/2)
	{
		dfs(pos+1,cnt1+1,cnt2,cnt3,sum+a[pos].z1);
		dfs(pos+1,cnt1,cnt2+1,cnt3,sum+a[pos].z2);
	}
	else dfs(pos+1,cnt1,cnt2,cnt3+1,sum+a[pos].z3);
	
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].z1>>a[i].z2>>a[i].z3;
			a[i].cha=a[i].z2-a[i].z1;
			if(a[i].z2!=0||a[i].z3!=0)
			{
				f1=0;
			}
			if(a[i].z3!=0)
			{
				f2=0;
			}
		}
		if(f1==1)
		{
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].z1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(f2==1)
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].z1;
			}
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].cha;
			}
			cout<<ans<<endl;
			continue;
		}
		else
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
