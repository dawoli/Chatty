#include<bits/stdc++.h>
using namespace std;
void case3(int n)
{
	if(n/7==1)
	{
		cout<<"40";
	}
	else if(n/7==2)
	{
		cout<<"200";
	}
	else
	{
		cout<<200;
		for(int i=0;i<n/7-2;i++)
		{
			cout<<8;
		}
		cout<<endl;		
	}
} 
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w".stdout);
	int t;
	cin>>t;
	int n;
	for(int a=0;a<t;a++)
	{
		cin>>n;
		if(n<=7)
		{
			switch(n)
			{
				case 1:
					cout<<-1<<endl;break;
				case 2:
					cout<<1<<endl;break;
				case 3:
					cout<<7<<endl;break;
				case 4:
					cout<<4<<endl;break;
				case 5:
					cout<<2<<endl;break;
				case 6:
					cout<<6<<endl;break;
				case 7:
					cout<<8<<endl;break;
			}
		}
		else
		{
			switch(n%7)
			{
				case 0:
				{
					for(int i=0;i<n/7;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
				case 1:
				{
					cout<<10;
					for(int i=0;i<n/7-1;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
				case 2:
				{
					cout<<1;
					for(int i=0;i<n/7;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
				case 3:
				{
					case3(n);
					break;
				}
				case 4:
				{
					cout<<20;
					for(int i=0;i<n/7-1;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
				case 5:
				{
					cout<<2;
					for(int i=0;i<n/7;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
				case 6:
				{
					cout<<6;
					for(int i=0;i<n/7;i++)
					{
						cout<<8;
					}
					cout<<endl;
					break;
				}
			}			
		}
	}
}
