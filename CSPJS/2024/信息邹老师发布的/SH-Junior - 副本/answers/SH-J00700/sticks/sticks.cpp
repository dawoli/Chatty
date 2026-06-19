#include <iostream>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		if (n==1) cout<<-1;
		else if (n==2) cout<<1;
		else if (n==3) cout<<7;
		else if (n==4) cout<<4;
		else if (n==5) cout<<2;
		else if (n==6) cout<<6;
		else if (n==7) cout<<8;
		else if (n==10) cout<<101;
		else if (n%7==0&&n/7>=0)
		{
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==1&&n/7>=1)
		{
			cout<<10;
			for (int i=1;i<=n/7-1;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==2&&n/7>=0)
		{
			cout<<1;
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==3&&n/7>=2)
		{
			cout<<200;
			for (int i=1;i<=n/7-2;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==4&&n/7>=1)
		{
			cout<<20;
			for (int i=1;i<=n/7-1;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==5&&n/7>=0)
		{
			cout<<2;
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==6&&n/7>=1)
		{
			cout<<80;
			for (int i=1;i<=n/7-1;i++)
			{
				cout<<8;
			}
		}
		else cout<<-1;
		cout<<endl;
	}
}
