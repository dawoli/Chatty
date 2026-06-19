#include<bits/stdc++.h>
using namespace std;
int t,n;
int do1();
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		do1();
	return 0;
} 

int do1()
{
	cin>>n;
	int k=n/7;
	if(n==3) {cout<<7<<endl;return 0;}
	if(n==4) {cout<<4<<endl;return 0;}
	if(n==10) {cout<<22<<endl;return 0;}
	if(n%7==0)
	{
		for(int i=1;i<=k;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==1 && n!=1)
	{
		cout<<10;
		for(int i=1;i<=k-1;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==2)
	{
		cout<<1;
		for(int i=1;i<=k;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==3)
	{
		cout<<200;
		for(int i=1;i<=k-2;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==4)
	{
		cout<<20;
		for(int i=1;i<=k-1;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==5)
	{
		cout<<2;
		for(int i=1;i<=k;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	if(n%7==6)
	{
		cout<<6;
		for(int i=1;i<=k;i++)
			cout<<8;
		cout<<endl;
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}
