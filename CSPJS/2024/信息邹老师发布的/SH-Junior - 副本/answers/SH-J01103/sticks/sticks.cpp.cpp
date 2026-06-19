#include <iostream>
#include <cstdio> 
using namespace std;
int index[15]={6,2,5,5,4,5,6,3,7,6}; 
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else if(n%7==1)
		{
			cout<<1;
			cout<<0;
			for(int i=1;i<=(n-8)/7;i++)
			{
				cout<<8;
			}
			cout<<endl;
		}
		else
		{
			cout<<5<<endl;
		}
	}
	return 0;
}
