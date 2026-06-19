#include<bits/stdc++.h>
using namespace std;

const string fileio="sticks";
int main()
{
	freopen((fileio+".in").c_str(),"r",stdin);
	freopen((fileio+".out").c_str(),"w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		if (n==1)
		{
			cout<<-1;
		}
		else if (n==2)
		{
			cout<<1;
		}
		else if (n==3)
		{
			cout<<7;
		}
		else if (n==4)
		{
			cout<<4;
		}
		else if (n==5)
		{
			cout<<2;
		}
		else if (n==6)
		{
			cout<<6;
		}
		else if (n%7==0)
		{
			int x=n/7;
			for (int i=1; i<=x; i++)
			{
				cout<<8;
			}
		}
		else if (n%7==1)
		{
			int x=n/7-1;
			cout<<27;
			for (int i=1; i<=x; i++)
			{
				cout<<8;
			}
		}
		else if (n%7==2)
		{
			int x=n/7;
			cout<<1;
			for (int i=1;i<=x;i++)
			{
				cout<<8;
			} 
		}
		else if (n%7==3)
		{
			int x=n/7-1;
			cout<<22;
			for (int i=1;i<=x;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==4)
		{
			int x=n/7-1;
			cout<<20;
			for (int i=1;i<=x;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==5)
		{
			int x=n/7;
			cout<<2;
			for (int i=1;i<=x;i++)
			{
				cout<<8;
			}
		}
		else if (n%7==6)
		{
			int x=n/7;
			cout<<6;
			for (int i=1;i<=x;i++)
			{
				cout<<8;
			}
		}
		cout<<endl;
	}
}
