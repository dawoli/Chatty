#include <iostream>
using namespace std;
int a[500005];
int n,k;
namespace A
{
	int MAIN()
	{
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==1) cnt++;
		}
		if (k==0)
		{
			cout<<cnt/2<<endl;
		}
		if (k==1)
		{
			cout<<cnt<<endl;
		}
	}
}
namespace B
{
	int u[500005];
	int s[500005][25];
	int MAIN()
	{
		int tot=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=25;j++)
			{
				s[i][j]=s[i-1][j];
			}
			int x=a[i];
			for (int j=1;x;j++)
			{
				if (x&1==1)
				{
					s[i][j]++;
				}
				x/=2;
			}
		}
		int x=k;
		for (int j=1;x;j++)
		{
			if (x&1==1)
			{
				s[n+1][j]++;
			}
			x/=2;
		}
//		for (int i=1;i<=n+1;i++)
//		{
//			for (int j=1;j<=25;j++)
//			{
//				cout<<s[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				bool flag=true;
				for (int k=1;k<=2;k++)
				{
//					cout<<i<<' '<<j<<' '<<k<<' '<<s[j][k]<<' '<<s[i-1][k]<<'\n';
					if (((s[j][k]-s[i-1][k])&1)!=(s[n+1][k]&1))
					{
						flag=false;
					}
				}
				if (flag)
				{
					u[i]=j;
					break;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (u[i]>=u[j]&&u[j]) u[i]=0;
			}
		}
//		for (int i=1;i<=n;i++)
//		{
//			cout<<u[i]<<' ';
//		}
		int ans=0;
		int y=0;
		for (int i=1;i<=n;i++)
		{
			if (u[i]==0||y>i) continue;
			y=u[i];
			ans++;
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=true;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]>1) flag=false;
	}
	if (k<=1&&flag) A::MAIN();
	else
	{
		B::MAIN();
	}
	return 0;
}
