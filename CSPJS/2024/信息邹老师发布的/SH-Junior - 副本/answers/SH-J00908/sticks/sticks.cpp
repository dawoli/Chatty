#include<bits/stdc++.h>
using namespace std;
int t,num[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		if (n<2)
		{
			cout<<-1<<endl;
			continue;
		}
		if (n<7)
		{
			for (int i=1;i<10;i++)
			{
				if (num[i]==n)
				{
					cout<<i<<endl;
					break;
				}
			}
			continue;
		}
		if (n%7==0)
		{
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==1)
		{
			cout<<10;
			for (int i=1;i<n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==2)
		{
			cout<<1;
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==3)
		{
			cout<<22;
			for (int i=1;i<n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==4)
		{
			cout<<20;
			for (int i=1;i<n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==5)
		{
			cout<<2;
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if (n%7==6)
		{
			cout<<6;
			for (int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
} 
