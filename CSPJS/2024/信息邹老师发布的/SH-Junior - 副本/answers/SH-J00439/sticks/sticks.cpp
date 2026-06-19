#include<bits/stdc++.h>
//#define int long long
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
struct node
{
	int num[10];
	bool have_;
	int si;
}dp[100010];
node add(node x,int y)
{
	x.num[y]++;
	x.si++;
	x.have_=1;
	return x;
}
node check(node x,node y)
{
	if(!x.have_)
	{
		return x;
	}
	if(!y.have_)
	{
		return y;
	}
	if(x.si!=y.si)
	{
		if(x.si<y.si)
		{
			return x;
		}
		else
		{
			return y;
		}
	}
	int xid,yid;
	for(int i=1;i<10;i++)
	{
		if(x.num[i]!=0)
		{
			xid=i;
			break;
		}
	}
	for(int i=1;i<10;i++)
	{
		if(y.num[i]!=0)
		{
			yid=i;
			break;
		}
	}
	if(xid!=yid)
	{
		if(xid<yid)
		{
			return x;
		}
		else
		{
			return y;
		}
	}
	for(int i=0;i<10;i++)
	{
		if(x.num[i]!=y.num[i])
		{
			if(x.num[i]>y.num[i])
			{
				return x;
			}
			else
			{
				return y;
			}
		}
	}
	return x;
}
void ans_out(int x)
{
	node ans=dp[x];
	if(!ans.have_)
	{
		cout<<-1<<endl;
		return;
	}
	int fir;
	for(int i=1;i<10;i++)
	{
		if(ans.num[i]!=0)
		{
			ans.num[i]--;
			fir=i;
			break;
		}
	}
	cout<<fir;
	for(int i=0;i<10;i++)
	{
		for(int j=1;j<=ans.num[i];j++)
		{
			printf("%d",i);
		}
	}
	cout<<endl;
}
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<10;j++)
		{
			dp[i].num[j]=0;
			dp[i].have_=0;
			dp[i].si=0;
		}
	}
	for(int i=2;i<=100000;i++)
	{
		bool flag=1;
		node minn;
		for(int j=0;j<10;j++)
		{
			if(stick[j]<=i)
			{	
				if(j==0&&(!dp[i-stick[j]].have_))
				{
					continue;
				}
				if(i-stick[j]==1)
				{
					continue;
				}
				if(flag)
				{
					minn=add(dp[i-stick[j]],j);
					flag=0;
				}
				else
				{
					minn=check(add(dp[i-stick[j]],j),minn);
				}
			}
		}
		dp[i]=minn;
	}
//	for(int i=0;i<10;i++)cout<<dp[8].num[i]<<endl;
//	cout<<dp[8].have_<<" "<<dp[8].si<<endl;
//	ans_out(8);
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		ans_out(x);
	}
	return 0;
}
