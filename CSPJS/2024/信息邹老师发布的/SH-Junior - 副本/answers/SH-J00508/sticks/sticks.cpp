#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,t,sum,mod;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n<=1)
		{
			cout<<-1<<endl;
		}
		else
		{
			if(n==2)
			{
				cout<<1<<endl;
			}
			if(n==3)
			{
				cout<<7<<endl;
			}
			if(n==4)
			{
				cout<<4<<endl;
			}
			if(n==5)
			{
				cout<<2<<endl;
			}
			if(n==6)
			{
				cout<<6<<endl;
			}
			if(n==7)
			{
				cout<<8<<endl;
			}
			if(n>7)
			{
				sum=n/7;
				mod=n%7;
				if(mod==0)
				{
					for(int j=1;j<=sum;j++)
					{
						cout<<8;
					}
					cout<<endl;
				}
				if(mod==1)
				{
					cout<<1<<0;
					for(int j=1;j<=sum-1;j++)
					{
						cout<<8;
					}
					cout<<endl;
				}
				if(mod==2)
				{
					cout<<1;
					for(int j=1;j<=sum;j++)
					{
						cout<<8;
					}
					cout<<endl;
				}
				if(mod==3)
				{
					cout<<2<<2;
					for(int j=1;j<=sum-1;j++)
					{
						cout<<8;
					}
					cout<<endl;
				}
				if(mod==4)
				{
					cout<<2<<0;
					for(int j=1;j<=sum-1;j++)
					{
						cout<<8;
					}
				}
				if(mod==5)
				{
					cout<<2;
					for(int j=1;j<=sum;j++)
					{
						cout<<8;
					}
				}
				if(mod==6)
				{
					cout<<6;
					for(int j=1;j<=sum;j++)
					{
						cout<<8;
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
