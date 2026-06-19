#include <bits/stdc++.h>
using namespace std;
int t,k;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k<=1) cout<<-1<<endl;
		if(k==2) cout<<1<<endl;
		if(k==3) cout<<7<<endl;
		if(k==4) cout<<6<<endl;
		if(k==5) cout<<2<<endl;
		if(k==6) cout<<6<<endl;
		if(k%7==0&&k!=0) 
		{
			for(int i=1;i<=k/7;i++)
			{
				cout<<8;
			}
			cout<<endl;	
		}
		if(k%7==1&&k!=1) 
		{
			cout<<10;
			for(int i=1;i<=(k-8)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;	
		}
		if(k%7==2&&k!=2) 
		{
			cout<<1;
			for(int i=1;i<=(k-1)/7;i++)
			{
				cout<<8;
			}	
			cout<<endl;
		}
		if(k%7==3&&k!=3) 
		{
			cout<<22;
			for(int i=1;i<=(k-10)/7;i++)
			{
				cout<<8;
			}	
			cout<<endl;
		}
		if(k%7==4&&k!=4) 
		{
			cout<<20;
			for(int i=1;i<=(k-11)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;	
		}
		if(k%7==5&&k!=5) 
		{
			cout<<2;
			for(int i=1;i<=(k-5)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;	
		}
		if(k%7==6&&k!=6) 
		{
			cout<<6;
			for(int i=1;i<=(k-6)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;	
		}
	}
	return 0;
}
