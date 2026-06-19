#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};

void dfs(int n,int wei,bool first)
{
	if(n==2)
	{
		cout<<"1";
		return;
	}
	if(n==3)
	{
		cout<<"7";
		return;
	}
	if(n==4)
	{
		cout<<"4";
		return;
	}
	if(n==5)
	{
		cout<<"2";
		return;
	}
	if(n==6)
	{
		if(!first) cout<<"0";
		else cout<<"6";
		return;
	}
	if(n==7)
	{
		cout<<"8";
		return;
	}
	int start;
	if(first) start=1;
	else start=0;
	for(int i=start;i<=9;i++)
	{
		if(n-num[i]>7*(wei-1)) continue;
		cout<<i;
		dfs(n-num[i],wei-1,0);
		break;
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
		if(n<=1)
		{
			cout<<"-1\n";
			continue;
		}
		if(n%7==0)//A
		{
			for(int i=1;i<=n/7;i++)
				cout<<"8";
			cout<<"\n";
			continue;
		}
		else if(n%7==1)//B
		{
			cout<<"10";
			for(int i=2;i<=n/7;i++)
				cout<<"8";
			cout<<"\n";
			continue;
		}
		int wei=(n-1)/7+1;
		dfs(n,wei,1);
		cout<<"\n";
	}
	return 0;
}
