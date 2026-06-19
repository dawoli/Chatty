#include <bits/stdc++.h>
using namespace std;
int times;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>times;
	while(times>0)
	{
		times--;
		int n;
		cin>>n;
		if(n<=1)
		{
			cout<<-1<<endl;
			continue;
		}
		int m=(n+6)/7,yushu=n%7;
		if(yushu==0)
		{
			for(int i=1;i<=m;i++)
				cout<<8;
			cout<<endl;
			continue;
		}
		if(m==1)
		{
			if(yushu==2)
				cout<<1;
			else if(yushu==3)
				cout<<7;
			else if(yushu==4)
				cout<<4;
			else if(yushu==5)
				cout<<2;
			else if(yushu==6)
				cout<<6;
		}
		else
		{
			m-=2;
			if(yushu==1)
				cout<<10;
			else if(yushu==2)
				cout<<18;
			else if(yushu==3)
				cout<<22;
			else if(yushu==4)
				cout<<20;
			else if(yushu==5)
				cout<<28;
			else if(yushu==6)
				cout<<68;
			for(int i=0;i<m;i++)
				cout<<8;
		}
		cout<<endl;
	}
}
