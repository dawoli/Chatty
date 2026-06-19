#include <iostream>
#include <cstdio>
using namespace std;
int list[21]={0,-1,1,7,4,2,6};
int n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<7) cout<<list[n]<<endl;
		else if(n%7==0)
		{
			for(int i=1; i<=n/7; i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1)
		{
			cout<<10;
			for(int i=1; i<=(n-8)/7; i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==3)
		{
			if(n==10) cout<<22<<endl;
			else 
			{
				cout<<200;
				for(int i=1;i<=(n-17)/7;i++) cout<<8;
				cout<<endl;
			}
		}
		else if(n%7==4)
		{
			cout<<20;
			for(int i=1;i<=(n-11)/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++) cout<<8;
			cout<<endl;
		}
		else
		{
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++) cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
