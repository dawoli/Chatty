#include<bits/stdc++.h>
using namespace std;
const int a[7]={-1,-1,1,7,4,2,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n<7)
		    cout<<a[n];
		else if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			    cout<<8;
		}
		else if(n%7==1)
		{
			cout<<10;
			for(int i=1;i<=n/7-1;i++)
			    cout<<8;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=n/7;i++)
			    cout<<8;
		}
		else if(n%7==3)
		{
			if(n==10)
			    cout<<22;
			else
			{
				cout<<200;
				for(int i=1;i<=n/7-2;i++)
				    cout<<8;
			}
		}
		else if(n%7==4)
		{
			cout<<20;
			for(int i=1;i<=n/7-1;i++)
			    cout<<8;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=n/7;i++)
			    cout<<8;
		}
		else if(n%7==6)
		{
			cout<<6;
			for(int i=1;i<=n/7;i++)
			    cout<<8;
		}
		cout<<"\n";
	}
	return 0;
}
