#include<bits/stdc++.h>
using namespace std;
int t,a;
int ans[20]={0,0,1,7,3,2,6,8,10,18,22,20,28,68};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a;
		if(a==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(a<14)
		{
			cout<<ans[a]<<endl;
			continue;
		}
		if(a%7==1)
		{
			int k=a/7-1;
			a=a%7+7;
			cout<<10;
			for(int i=1;i<=k;i++) cout<<8;
			cout<<endl;
			continue;
		}
		if(a%7==3)
		{
			int k=a/7-2;
			a=a%7+7;
			cout<<200;
			for(int i=1;i<=k;i++) cout<<8;
			cout<<endl;
			continue;
		}
		int k=a/7-1;
		a=a%7+7;
		if(a!=0)
		{
			cout<<ans[a];
		}
		for(int i=1;i<=k;i++) cout<<8;
		cout<<endl;
	}
	return 0;
}
