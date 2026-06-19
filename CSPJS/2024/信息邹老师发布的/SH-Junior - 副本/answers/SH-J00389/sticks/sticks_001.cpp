#include<bits/stdc++.h>
using namespace std;
unsigned long long t,n,sum,a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int k=1;
		while(1)
		{
			if((n-1)%7==0)
			{
				cout<<10;
				for(int j=1;j<=(n-1)/7-1;j++)
				{
					cout<<8;
				}
				cout<<endl;
				break;
			}
			if(n%7==0)
			{
				for(int j=1;j<=n/7;j++)
				{
					cout<<8;
				}
				cout<<endl;
				break;
			}
			sum=0;
			int x=k;
			while(x>0)
			{
				sum+=a[x%10];
				x/=10;
			}
			if(sum==n)
			{
				cout<<k<<endl;
				break;
			}
			if(n<2)
			{
				cout<<-1;
				break;
			}
			k++;
		}
	}
	return 0;
}
