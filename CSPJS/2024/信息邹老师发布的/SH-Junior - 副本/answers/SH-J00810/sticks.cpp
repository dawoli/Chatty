#include<iostream>
using namespace std;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	int num[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]%7!=0)
		{
			if(num[i]%7==1)
			{
				cout<<10;
			}
			else
			cout<<num[i];
		}
		else
		cout<<8;
		for(int i=1;i<=num[i]/7-1;i++)
		{
			cout<<8;
		}
		cout<<endl;
	}
	return 0;
}
