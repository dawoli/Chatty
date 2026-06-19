#include<bits/stdc++.h>
using namespace std;
int T,n;
int nums[10]={6,2,5,5,4,5,6,3,7,6};
int anss[21]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,68,88,108,188,200,208,288,688};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=20)cout<<anss[n];
		else if(n%7==0)for(int i=1;i<=n/7;i++)cout<<8;
		else if(n%7==1)
		{
			cout<<10;
			for(int i=1;i<n/7;i++)cout<<8;
		}
		else if(n%7==2)
		{
			cout<<1;
			for(int i=1;i<=n/7;i++)cout<<8;
		}
		else if(n%7==3)
		{
			cout<<200;
			for(int i=1;i<=n/7-2;i++)cout<<8;
		}
		else if(n%7==4)
		{
			cout<<20;
			for(int i=1;i<n/7;i++)cout<<8;
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i=1;i<=n/7;i++)cout<<8;
		}
		else if(n%7==6)
		{
			cout<<6;
			for(int i=1;i<=n/7;i++)cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
