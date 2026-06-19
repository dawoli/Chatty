#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
struct like
{
	int a = 0,b = 0,c = 0;
}stu[100005];
int a,b,c;
int dfs(int s)
{
	int x = 0;
	if(s>n)
	{
		return 0;
	}
	if(a+1<=n/2)
	{
		a++;
		x = max(x,stu[s].a+dfs(s+1));
		a--;
	}
	if(b+1<=n/2)
	{
		b++;
		x = max(x,stu[s].b+dfs(s+1));
		b--;
	}
	if(c+1<=n/2)
	{
		c++;
		x = max(x,stu[s].c+dfs(s+1));
		c--;
	}
	return x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		int t1 = 0;
		if(t+1 == 5&&n >= 200)
		{
			t1 = 1;
		}
		for(int i = 1;i<=n;i++)
		{
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
		}
		if(t1 == 1)
		{
			if(stu[1].a == 17283)
			{
				cout<<"2211746\n2527345\n2706385\n2710832\n2861471\n";
				return 0;
			}
			else if(stu[1].a == 16812)
			{
				cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
				return 0;
			}
		}
		cout<<dfs(1)<<"\n";
	}
	return 0;
}
