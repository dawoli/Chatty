#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int a[20]={-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2)
		{
			cout<<-1<<'\n';
			continue;
		}
		if(n<=20)
		{
			cout<<a[n-1]<<'\n';
			continue;
		}
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<'\n';
			continue;			
		}
		if(n%7==1)
		{
			cout<<10;
			n-=8;
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<'\n';
			continue;
		}
		int ans[50004],cnt=n/7,t=n%7;
		int d[10]={6,2,5,5,4,5,6,3,7,6};
		n%=7;
		if(t==2) ans[1]=1;
		else if(t==3) ans[1]=7;
		else if(t==4) ans[1]=4;
		else if(t==5) ans[1]=2;
		else if(t==6) ans[1]=6;
		for(int i=2;i<=cnt+1;i++) ans[i]=8;
		for(int i=1;i<=cnt+1;i++) cout<<ans[i];
		cout<<'\n';
	}
	return 0;
}
