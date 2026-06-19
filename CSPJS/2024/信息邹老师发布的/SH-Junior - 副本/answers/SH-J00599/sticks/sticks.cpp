#include <bits/stdc++.h>
using namespace std;
long long n,t,x,k,y;
void solve1()
{
	x=n/7;
	for(int i=1;i<=x;i++)
	{
		cout <<8;
	}
	cout <<endl;
	return;
}
void solve2()
{
	cout <<10;
	k=(n-8)/7;
	for(int i=1;i<=k;i++)
	{
		cout <<8;
	}
	cout <<endl;
	return;
}
void solve3()
{
	if(n%7==2)
	{
		cout <<1;
		y=(n-2)/7;
		for(int i=1;i<=y;i++)
		{
			cout <<8;
		}
		cout <<endl;
	}
	else if(n%7==3)
	{
		cout <<22;
		y=(n-10)/7;
		for(int i=1;i<=y;i++)
		{
			cout <<8;
		}
		cout <<endl;
	}
	else if(n%7==4)
	{
		cout <<20;
		y=(n-11)/7;
		for(int i=1;i<=y;i++)
		{
			cout <<8;
		}
		cout <<endl;
	}
	else if(n%7==5)
	{
		cout <<2;
		y=(n-5)/7;
		for(int i=1;i<=y;i++)
		{
			cout <<8;
		}
		cout <<endl;
	}
	else if(n%7==6)
	{
		cout <<6;
		y=(n-6)/7;
		for(int i=1;i<=y;i++)
		{
			cout <<8;
		}
		cout <<endl;
	}
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >>t;
	while(t--)
	{
		cin >>n;
		if(n<=8)
		{
			if(n==1)
			{
				cout <<-1 <<endl;
				
			}
			else if(n==2)
			{
				cout <<1 <<endl;
			}
			else if(n==3)
			{
				cout <<7 <<endl;
			}
			else if(n==4)
			{
				cout <<4 <<endl;
			}
			else if(n==5)
			{
				cout <<5 <<endl;
			}
			else if(n==6)
			{
				cout <<6 <<endl;
			}
			else if(n==7)
			{
				cout <<8 <<endl;
			}
		}
		else if(n>=8)
		{
			if(n%7==0)
			{
				solve1();
			}
			else if(n%7==1)
			{
				solve2();
			}
			else
			{
				solve3();
			}
		}
	}
}
