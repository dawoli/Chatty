#include<bits/stdc++.h>
using namespace std;

int t,n,a,v[8]={0,0,1,7,4,2,6,8};
bool o;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2)
		{
			cout<<-1;
		}
		else if(n<=7)
		{
			cout<<v[n];
		}
		else if(n%7==0)
		{
			a=n/7;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==1)
		{
			cout<<10;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==2)
		{
			cout<<18;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==3)
		{
			cout<<22;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==4)
		{
			cout<<20;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==5)
		{
			cout<<28;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		else if(n%7==6)
		{
			cout<<68;
			a=n/7-1;
			for(int i=1;i<=a;i++)
			{
				cout<<8;
			}
		}
		cout<<endl;
	}
	return 0;
}

