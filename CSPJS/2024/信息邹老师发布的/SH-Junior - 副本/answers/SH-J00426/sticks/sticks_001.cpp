#include<bits/stdc++.h>
using namespace std;
int ans;
int tens;
void check(int n)
{
	if(n==1)
	{
		ans=-1;
	}
	else if(n==2)
	{
		ans=1;
	}
	else if(n==3)
	{
		ans=7;
	}
	else if(n==4)
	{
		ans=4;
	}
	else if(n==5)
	{
		ans=2;
	}
	else if(n==6)
	{
		ans=6;
	}
	else if(n==7)
	{
		ans=8;
	}
	else if(n==8)
	{
		ans+=10*tens;
	}
	else if(n==9)
	{
		ans+=18*tens;
	}
	else if(n==10)
	{
		ans+=22*tens;
	}
	else if(n==11)
	{
		ans+=20*tens;
	}
	else if(n==12)
	{
		ans+=28*tens;
	}
	else if(n==13)
	{
		ans+=68*tens;
	}
	else if(n==14)
	{
		ans+=88*tens;
	}
	else
	{
		n-=7;
		ans+=8*tens;
		tens*=10;
		check(n);
	}
	return;
}


int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	int round;
	for(round=1;round<=t;round++)
	{
		int n;
		cin>>n;
		ans=0;
		tens=1;
		check(n);
		cout<<ans<<endl;
		ans=0;
		tens=1;
	}
	return 0;
}
