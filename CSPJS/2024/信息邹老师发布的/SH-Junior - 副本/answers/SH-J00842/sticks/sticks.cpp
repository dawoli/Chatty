#include<bits/stdc++.h>
using namespace std;
const int ans[25]={0,-1,1,7,4,2,6,8,10,18,40,20};
int t,b[60];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		cin>>b[i];
	for(int i=1;i<=t;i++)
	{
		int n=b[i];
		if(b[i]>=1&&b[i]<=11)
		{
			cout<<ans[b[i]]<<endl;
			continue;
		}
		if(b[i]%7==0)
		{
			for(int j=1;j<=n/7;j++)
				cout<<"8";
			cout<<endl;
			continue;
		}
		if(b[i]%7==1)
		{
			cout<<"10";
			for(int j=1;j<=(n-8)/7;j++)
				cout<<"8";
			cout<<endl;
			continue;
		}
		if(b[i]%7==2)
		{
			cout<<"1";
			for(int j=1;j<=(n-2)/7;j++)
				cout<<"8";
			cout<<endl;
		}
		if(b[i]%7==3)
		{
			cout<<"22";
			for(int j=1;j<=(n-10)/7;j++)
				cout<<"8";
			cout<<endl;
		}
		if(b[i]%7==4)
		{
			cout<<"20";
			for(int j=1;j<=(n-11)/7;j++)
				cout<<"8";
			cout<<endl;
		}
		if(b[i]%7==5)
		{
			cout<<"2";
			for(int j=1;j<=(n-5)/7;j++)
				cout<<"8";
			cout<<endl;
		}
		if(b[i]%7==6)
		{
			cout<<"6";
			for(int j=1;j<=(n-5)/7;j++)
				cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}
