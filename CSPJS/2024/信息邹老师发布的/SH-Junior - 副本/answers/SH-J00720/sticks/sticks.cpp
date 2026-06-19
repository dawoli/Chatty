#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[10]={6,2,5,5,4,5,6,3,7,6};

void judge(int num,int c)
{
	if(c==0)
	{
	    ans=min(ans,num);
		return;
	}
	else
	{
		for(int i=0;i<10;i++)
		{
			if(i==3||i==5||i==6||i==9)continue;
			if(c>=a[i])
			{
				judge(num*10+i,c-a[i]);
			}
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0x3f3f3f;
		if(n==6)cout<<6;
		else if(n<20)
		{
			
		for(int i=1;i<=9;i++)
		{
			if(i==3||i==5||i==9)continue;
			if(n>=a[i]) 
			{
				judge(i,n-a[i]);
			}
		}
		if(ans==0x3f3f3f)
		{
			cout<<-1;
		}
		else 
		{
			cout<<ans;
	    }
		}
		else if(n>=20&&n<=50)
		{
			ans=0;
			int temp=0;
			while(n/7)
			{
				ans*=10;
				ans+=8;
				temp++;
			}
			if(n%7==1)
			{
				cout<<"-1";
				continue;
			}
			int x=0;
			for(int i=0;i<=9;i++)
			{
				if(a[i]==n)
				{
					x=i;
				}
			}
			cout<<ans + x*pow(10,temp);
		}
		else {
			int adsq=0;
			for(int i=1;i<=n/7;i++)
			{
				adsq*=10;
				adsq+=8;
			}
			cout<<adsq;
		}
		cout<<'\n';
	}
	return 0;
}

