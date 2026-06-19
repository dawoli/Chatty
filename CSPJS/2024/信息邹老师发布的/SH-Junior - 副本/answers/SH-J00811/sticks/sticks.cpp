#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[]={6,2,5,5,4,5,6,3,7,6};
string minn="8888888";
void dfs(int g,int sum,int f,string x)
{
	if(x.size()>minn.size())return;
	if(sum>g)return;
	if(sum==g)
	{
		if(x.size()<minn.size())
		{
			minn=x;
			return;
		}
		if(x<minn)minn=x;
		return;
	}
	for(int i = 0;i <= 9;i++)
	{
		if(i==0&&!f)continue;
		dfs(g,sum+a[i],1,x+char(i+'0'));
	}
}
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
		if(n%7==0)
		{
			for(int i = 1;i <= n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1)
		{
			if(n==1)cout<<-1<<endl;
			else 
			{
				cout<<10;
				for(int i = 1;i <= (n-8)/7;i++)
				{
					cout<<8;
				}
				cout<<endl;
			} 
		}
		else if(n%7==2)
		{
			if(n==2)cout<<1<<endl;
			else
			{
				cout<<1;
				for(int i = 1;i<=(n-2)/7;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
		else if(n%7==3)
		{
			if(n==3)cout<<7<<endl;
			else if(n==10)cout<<22<<endl;
			else 
			{
				cout<<200;
				for(int i = 1;i <= (n-17)/7;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
		else if(n%7==4)
		{
			if(n==4)cout<<11<<endl;
			else 
			{
				cout<<20;
				for(int i = 1;i <= (n-11)/7;i++)
				{
					cout<<8;
				}
				cout<<endl;
			}
		}
		else if(n%7==5)
		{
			cout<<2;
			for(int i = 1;i <= (n-5)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else
		{
			cout<<6;
			for(int i = 1;i<=(n-6)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
	}
	return 0;
}
