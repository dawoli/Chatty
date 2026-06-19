#include<bits/stdc++.h>
using namespace std;
int d[20]={6,2,5,-1,4,-1,6,3,7,-1};
string csts="";
void solve1(int n)
{
	int num=n/7;
	for(int i=1;i<=num;i++)
	{
		cout<<8;
	}
	cout<<endl;
}
string s2dg(int n,int now,int pl,int all,string s)
{
	if(pl>all&&now==n)
	{
		return s;
	}
	else if(pl>all)
	{
		return csts;
	}
	string ans=csts;
	for(int i=0;i<=9;i++)
	{
		if(pl==1&&i==0)
		{
			continue;
		}
		if(d[i]==-1)
		{
			continue;
		}
		if(now+d[i]<=n)
		{
			char x=i+'0';
			string a=s2dg(n,now+d[i],pl+1,all,s+x);
			if(a!=csts)
			{
				return a;
			}
		}
	}
	return csts;
}
void solve2(int n)
{
	int ws=(n+6)/7;
	string s="";
	cout<<s2dg(n,0,1,ws,s)<<endl;
}
void solve3(int n)
{
	int ws=(n-1)/7-1;
	cout<<10;
	for(int i=1;i<=ws;i++)
	{
		cout<<8;
	}
	cout<<endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=20000;i++)
	{
		csts+='9';
	 } 
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<-1<<endl;
		}
		else if(n%7==0)
		{
			solve1(n);
		}
		else if(n%7==1)
		{
			solve3(n);
		}
		else if(n<=50)
		{
			solve2(n);
		}
	}
	return 0;
}
