#include<bits/stdc++.h>
using namespace std;
int n,T,b,c,d;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int a=1;a<=T;a++)
	{
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<'8';
			}
		}
		if(n==1)
		cout<<-1;
		if(n==2)
		cout<<1;
		if(n==3)
		cout<<7;
		if(n==4)
		cout<<4;
		if(n==5)
		cout<<2;
		if(n==6)
		cout<<6;
		if(n==8)
		cout<<16;
		if(n==9)
		cout<<18;
		if(n==10)
		cout<<78;
		if(n==11)
		cout<<20;
		if(n==12)
		cout<<28;
		if(n==13)
		cout<<68;
		if(n==15)
		cout<<168;
		if(n==16)
		cout<<188;
		if(n==17)
		cout<<788;
		if(n==18)
		cout<<208;
		if(n==19)
		cout<<288;
		if(n==20)
		cout<<688;
		if(n>20&&n%7!=0)
		{
			b=n%7;
			d=n/7;
			if(b==1)
			{
				c=16;
				d--;
			}
			else if(b==2)
			c=1;
			else if(b==3)
			c=7;
			else if(b==4)
			{
				c=20;
				d--;
			}
			else if(b==5)
			c=2;
			else if(b==6)
			c=6;
			cout<<c;
			for(int i=1;i<=d;i++)
			cout<<'8';
		}
		cout<<endl;
	}
	return 0;
} 


