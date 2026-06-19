#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<2)
		{
			cout<<-1<<endl;
		}
		else
		{
			if(n<8)
			{
				if(n==2)
				{
					cout<<1;
				}
				if(n==3)
				{
					cout<<7;
				}
				if(n==4)
				{
					cout<<4;
				}
				if(n==5)
				{
					cout<<2;
				}
				if(n==6)
				{
					cout<<6;
				}
			}
			else
			{
				int num=n%7;
				if(num==0)
				{
					for(int i=1;i<=n/7;i++)
					{
						cout<<8;
					}
				}
				else if(num==1)
				{
					cout<<10;
					for(int i=1;i<=n/7-1;i++)
					{
						cout<<8;
					}
				}
				else if(num==2)
				{
					cout<<1;
					for(int i=1;i<=n/7;i++)
					{
						cout<<8;
					}
				}
				else if(num==3)
				{
					cout<<7;
					for(int i=1;i<=n/7;i++)
					{
						cout<<8;
					}
				}
				else if(num==4)
				{
					cout<<20;
					for(int i=1;i<=n/7-1;i++)
					{
						cout<<8;
					}
				}
				else if(num==5)
				{
					cout<<2;
					for(int i=1;i<=n/7;i++)
					{
						cout<<8;
					}
				}
				else if(num==6)
				{
					cout<<6;
					for(int i=1;i<=n/7;i++)
					{
						cout<<8;
					}
				}
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
