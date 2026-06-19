#include<iostream>
#include<cstdio>
#include<iomanip>
#include<fstream>
using namespace std;
int main()
{
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a[8]={-1,-1,1,7,4,2,0,8},b[8]={6,2,5,4,-1,-1,3,7};
	int t;
	cin>>t;
	for(int m=1;m<=t;m++)
	{
		int howmany;
		cin>>howmany;
		int s=howmany/7;
		int k=howmany%7;
		if(k==0)
		{
			for(int i=1;i<=s;i++)
			{
				cout<<8; 
				return 0;
			}
			cout<<endl;
			continue;
		}
		else if(k==1)
		{
			if(howmany==1)
			{
				cout<<-1;
				cout<<endl;
				continue; 
			}
			else
			{
				cout<<1<<0;
				for(int i=1;i<=s-1;i++)
				{
					cout<<8;
				}
				cout<<endl;
				continue;
			}
		}
		else if(k==2)
		{
			cout<<1;
			for(int i=1;i<=s;i++)
			{
				cout<<8;
			} 
			cout<<endl;
			continue;
		}
		else if(k==3)
		{
			if(howmany==3)
			{
				cout<<7<<endl;
				continue;
			}
			else if(howmany==10)
			{
				cout<<40<<endl;
				continue;
			}
			else
			{
				cout<<200;
				for(int i=1;i<=s-2;i++)cout<<8;
				cout<<endl;
				continue;
			}
		}
		else if(k==4)
		{
			if(howmany==4)
			{
				cout<<4<<endl;
				continue;
			}
			else if(howmany==11)
			{
				cout<<20<<endl;
				continue;
			}
			else if(howmany==18)
			{
				cout<<208<<endl;
				continue; 
			}
			else if(howmany==25)
			{
				cout<<2088<<endl;
				continue; 
			}
			else
			{
				cout<<10000;
				for(int i=1;i<=s-4;i++)cout<<8;
				cout<<endl;
				continue;
			}
		}
		else if(k==5)
		{
			if(howmany==5)
			{
				cout<<2<<endl;
				continue;
			}
			else
			{
				cout<<10;
				for(int i=1;i<=s-1;i++)
				{
					cout<<8;
				}
				cout<<endl;
				continue;
			}
		}
		else
		{
			if(howmany==6)
			{
				cout<<6<<endl;
				continue;
			}
			else if(howmany==13)
			{
				cout<<80<<endl;
				continue;	
			}
			else 
			{
				cout<<100;
				for(int i=1;i<=s-2;i++)
				{
					cout<<8;
				}
				cout<<endl;
				continue;
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
