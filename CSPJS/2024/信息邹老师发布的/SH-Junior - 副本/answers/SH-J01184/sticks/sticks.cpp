#include<bits/stdc++.h>
using namespace std;
void solve(int n)
{
	string s;
	if(n%7==0)
	{
		int d=n/7;
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==1&&n!=1)
	{
		int d=(n-8)/7;
		s+='1';
		s+='0';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==2&&n!=2)
	{
		int d=(n-2)/7;
		s+='1';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==3&&n!=3)
	{
		int d=(n-10)/7;
		s+='2';
		s+='5';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==4&&n!=4)
	{
		int d=(n-11)/7;
		s+='2';
		s+='0';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==5&&n!=5)
	{
		int d=(n-5)/7;
		s+='2';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n%7==6&&n!=6)
	{
		int d=(n-13)/7;
		s+='2';
		s+='8';
		for(int i=1;i<=d;i++)
			s+='8';
		cout<<s<<endl;
		return;
	}
	if(n==1)
	{
		cout<<-1<<endl;
		return;
	}
	if(n==2)
	{
		cout<<1<<endl;
		return;
	}
	if(n==3)
	{
		cout<<7<<endl;
		return;
	}
	if(n==4)
	{
		cout<<4<<endl;
		return;
	}
	if(n==5)
	{
		cout<<2<<endl;
		return;
	}
	if(n==6)
	{
		cout<<6<<endl;
		return;
	}
}
int main()
{	
	freopen("sticks.in","w",stdin);
	freopen("sticks.out","r",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;
		cin>>n;
		solve(n);
	}
	return 0;
}
