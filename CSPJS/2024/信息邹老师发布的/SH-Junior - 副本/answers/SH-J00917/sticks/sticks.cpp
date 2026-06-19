#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n==3)
		{
			cout<<7<<endl;
			continue;
		}
		if(n==4)
		{
			cout<<4<<endl;
			continue;
		}
		if(n==10)
		{
			cout<<22<<endl;
			continue;
		}
		int a;
		a=n/7;
		n%=7;
		if(n==0)
		{
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==1)
		{
			a--;
			cout<<10;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==2)
		{
			cout<<1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==3)
		{
			cout<<200;
			a-=2;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==4)
		{
			cout<<20;
			a-=1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==5)
		{
			cout<<2;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		if(n==6)
		{
			cout<<6;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		cout<<endl;
	}
	return 0;
}
