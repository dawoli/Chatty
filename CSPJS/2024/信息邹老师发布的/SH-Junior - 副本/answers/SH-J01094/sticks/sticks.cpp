#include<bits/stdc++.h>

using namespace std;

int t,n,sum,m,cnt;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n <= 1)
		{
			cout<<"-1"<<"\n";
			continue;
		}
		if(n % 7 == 0)
		{
			for(int i = 1;i <= n/7;i++)
			{
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 1)
		{
			cout<<"10";
			for(int i = 1;i <= (n-8)/7;i++)
			{
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 2)
		{
			cout<<"1";
			for(int i = 1;i <= (n-2)/7;i++)
			{
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 3)
		{
			if(n == 3)
			{
				cout<<7;
			}
			else if(n == 10)
			{
				cout<<"20";
			}
			else
			{
				cout<<"200";
				for(int i = 1;i <= n/7-2;i++)
				{
					cout<<8;
				}
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 4)
		{
			if(n == 4)
			{
				cout<<4;
			}
			else
			{
				cout<<"20";
				for(int i = 1;i <= n/7-1;i++)
				{
					cout<<8;
				}
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 5)
		{
			cout<<2;
			for(int i = 1;i <= n/7;i++)
			{
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
		if(n % 7 == 6)
		{
			cout<<6;
			for(int i = 1;i <= n/7;i++)
			{
				cout<<8;
			}
			cout<<"\n";
			continue;
		}
	}
	return 0;
} 
