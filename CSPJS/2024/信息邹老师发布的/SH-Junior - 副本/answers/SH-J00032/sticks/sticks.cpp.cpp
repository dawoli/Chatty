#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int num1[10]={0,-1,1,7,4,2,6,8};
int num2[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int n,t,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n%7==0)
		{
			for(int j=1;j<=n/7;j++)
				{
					ans*=10;
					ans+=8;
				}
				cout<<ans;
		}
		else
		{
			if(n<=7)
			{
				cout<< num1[n];
				continue;
			}
			int x=ceil(n/0.01*0.01/7),fx=1,ans=0;
			while(n-num2[fx]>=(x-1)*7)
			{
				fx++;
			}
			n-=num2[fx];
			x--;
			ans+=fx;

			while(n>0)
			{
				fx=0;
				while(n-num2[fx]>(x-1)*7)
				{
					fx++;
				}
				ans*=10;
				ans+=fx;
				n-=num2[fx];
				x--;
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
