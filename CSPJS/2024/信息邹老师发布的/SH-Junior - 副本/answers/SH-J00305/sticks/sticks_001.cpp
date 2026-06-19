#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
const int MAXN=10000000;
int b[MAXN];
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=MAXN-1;i++)
	{
		int s=i;
		while(s)
		{
			b[i]+=a[s%10];
			s/=10;
		}
	}
	for(int i=1;i<=t;i++)
	{
		int k;
		cin>>k;
		if(k==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(k%7==0)
		{
			for(int j=1;j<=k/7;j++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		if(k%7==1)
		{
			cout<<10;
			for(int j=1;j<=k/7-1;j++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
//		bool l=false;
		for(int i=1;i<=MAXN-1;i++)
		{
			if(b[i]==k)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}//O(10000000t)
