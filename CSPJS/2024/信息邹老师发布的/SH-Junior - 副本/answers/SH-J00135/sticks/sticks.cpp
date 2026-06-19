#include <bits/stdc++.h>
using namespace std;
int s[]={6,2,5,5,4,5,6,3,7,6};
int t,n;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==1 && n>7)
		{
			cout<<10;
			for(int i=1;i<=n/7-1;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==3 && n>7)
		{
			cout<<22;
			for(int i=1;i<=n/7-1;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==4 && n>7)
		{
			cout<<20;
			for(int i=1;i<=n/7-1;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n%7==6 )
		{
			cout<<6;
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<endl;
		}
		else if(n<2) cout<<-1<<endl;		
		else if(n==3) cout<<7<<endl;
		else if(n==4) cout<<4<<endl;
	}
	return 0;
 } 
