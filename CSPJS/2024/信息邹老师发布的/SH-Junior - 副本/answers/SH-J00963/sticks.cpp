#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n,ans;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n;
		ans=0;
		if (n==1)	cout<<-1<<endl;
		else if(n==3)	cout<<7<<endl;
		else if(n==4)	cout<<4<<endl;
		else if(n==6)	cout<<6<<endl;
		else if(n%7==0)
		{
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==1)
		{
			ans=10;
			n=n-8;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==2)
		{
			ans=1;
			n=n-2;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==3)
		{
			ans=22;
			n=n-10;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==4)
		{
			ans=20;
			n=n-11;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==5)
		{
			ans=2;
			n=n-5;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
		else if(n%7==6)
		{
			ans=80;
			n=n-13;
			while (n!=0)
			{
				ans=ans*10+8;
				n=n-7;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
