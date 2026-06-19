#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		if (n%7==0) 
		{
			for (int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1&&n!=1)
		{
			cout<<10;
			for (int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==2)
		{
			cout<<1;
			for (int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==3&&n!=3)
		{
			cout<<22;
			for (int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==4&&n!=4)
		{
			cout<<20;
			for (int j=1;j<n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<2;
			for (int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}
		else if(n%7==6)
		{
			cout<<6;
			for (int j=1;j<=n/7;j++) cout<<8;
			cout<<endl;
		}
		else if (n==1) cout<<-1<<endl;
		else if (n==3) cout<<7<<endl;
		else if (n==4) cout<<4<<endl;
	}
	return 0;
}
