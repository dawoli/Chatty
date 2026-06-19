#include<bits/stdc++.h>
using namespace std;

int n,x,ans;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x;
		if(x==1)cout<<-1<<endl;
		else if(x==2)cout<<1<<endl;
		else if(x==3)cout<<7<<endl;
		else if(x==4)cout<<4<<endl;
		else if(x==5)cout<<2<<endl;
		else if(x==6)cout<<6<<endl;
		else if(x==7)cout<<8<<endl;
		else if(x==8)cout<<10<<endl;
		else if(x==9)cout<<18<<endl;
		else if(x==10)cout<<22<<endl;
		else if(x==11)cout<<20<<endl;
		else if(x==12)cout<<28<<endl;
		else if(x==13)cout<<68<<endl;
		else if(x==14)cout<<88<<endl;
		else if(x%7==3)
		{
			cout<<200;
			for(int i=1;i<=x/7-2;i++)cout<<8;
			cout<<endl;
		}
		else if(x%7==0)
		{
			cout<<88;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}
		else if(x%7==1)
		{
			cout<<10;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}else if(x%7==2)
		{
			cout<<18;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}else if(x%7==4)
		{
			cout<<20;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}else if(x%7==5)
		{
			cout<<28;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}else if(x%7==6)
		{
			cout<<68;
			for(int i=1;i<=x/7-1;i++)cout<<8;
			cout<<endl;
		}
	}
	return 0;
}
