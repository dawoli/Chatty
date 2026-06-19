#include<iostream>
#include<cstring>
using namespace std;
#define int long long
int a[100010];
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		memset(a,0,sizeof(a)); 
		int t;
		cin>>t;
		if(t==1)
		{
			cout<<-1<<endl;
			continue;
		} 
		else if(t==2)
		{
			cout<<1<<endl;
		}
		else if(t==3)
		{
			cout<<7<<endl;
		}
		else if(t==4)
		{
			cout<<4<<endl;
		}
		else if(t==5)
		{
			cout<<2<<endl;
		}
		else if(t==6)
		{
			cout<<6<<endl;
		}
		else if(t==7)
		{
			cout<<8<<endl;
		}
		else
		{
			int tn=t/7;
			if(t%7!=0)
			{
				tn+=1;
			}
			else
			{
				for(int i=1;i<=tn;i++)
				{
					cout<<8;
				}
				cout<<endl;
				continue;
			}
			for(int i=2;i<=tn;i++)
			{
				a[i]=8;
			}
			if(t%7==6)
			{
				a[1]=6;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
			else if(t%7==1)
			{
				a[1]=1;
				a[2]=0;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
			if(t%7==5)
			{
				a[1]=2;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
			if(t%7==2)
			{
				a[1]=1;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
			if(t%7==4)
			{
				a[1]=2;
				a[2]=0;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
			if(t%7==3);
			{
				a[1]=2;
				a[2]=2;
				for(int i=1;i<=tn;i++)
				{
					cout<<a[i];
				}
				cout<<endl;
				continue;
			}
		}
	}
	return 0;
}
