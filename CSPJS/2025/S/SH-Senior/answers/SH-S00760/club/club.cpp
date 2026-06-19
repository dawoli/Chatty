#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005][5];
int n;
namespace A
{
	int ans=0;
	inline void dfs(int step,int sum1,int sum2,int sum3,int sum)
	{
		if (sum1>n/2||sum2>n/2||sum3>n/2)
		{
			return;
		}
		if (step>n)
		{
			ans=max(ans,sum);
			return;
		}
		dfs(step+1,sum1+1,sum2,sum3,sum+a[step][1]);
		dfs(step+1,sum1,sum2+1,sum3,sum+a[step][2]);
		dfs(step+1,sum1,sum2,sum3+1,sum+a[step][3]);
	}
	int MAIN()
	{
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
	}
}
namespace B
{
	int b[100005];
	bool cmp(int x,int y)
	{
		return x>y;
	}
	int MAIN()
	{
		for (int i=1;i<=n;i++)
		{
			b[i]=a[i][1];
		}
		sort(b+1,b+n+1,cmp);
		int sum=0;
		for (int i=1;i<=n/2;i++)
		{
			sum+=b[i];
		}
		cout<<sum<<endl;
	}
}
namespace C
{
	int b[100005];
	bool cmp(int x,int y)
	{
		return x<y;
	}
	int MAIN()
	{
		int sum1=0,sum2=0,ans=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i][1]>a[i][2])
			{
				sum1++;
				ans+=a[i][1];
			}
			else
			{
				sum2++;
				ans+=a[i][2];
			}
		}
		if (sum1<=n/2&&sum2<=n/2)
		{
			cout<<ans<<endl;
			return 0;
		}
		if (sum1>n/2)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i][1]>a[i][2])
				{
					b[i]=a[i][1]-a[i][2];
				}
			}
		}
		if (sum2>n/2)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i][2]>a[i][1])
				{
					b[i]=a[i][2]-a[i][1];
				}
			}
		}
		sort(b+1,b+n+1,cmp);
		for (int i=1;i<=max(sum1,sum2)-n/2;i++)
		{
			ans-=b[i];
		}
		cout<<ans<<endl;
	}
}
namespace D
{
	int MAIN()
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			sum+=max(max(a[i][1],a[i][2]),a[i][3]);
			
		}
		cout<<sum<<endl;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		bool flag1=true,flag2=true;
		cin>>n;
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if (a[i][2]) flag1=false;
			if (a[i][3]) flag2=false;
		}
		if (flag1&&flag2)
		{
			B::MAIN();
		}
		else if (flag2)
		{
			C::MAIN();
		}
		else if (n<=20)
		{
			A::MAIN();
		}
		else
		{
			D::MAIN();
		}
	}
	return 0;
}
