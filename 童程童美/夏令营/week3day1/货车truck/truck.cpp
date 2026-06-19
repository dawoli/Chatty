#include<iostream>
using namespace std;
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	int n,sum=0,p;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p;
		sum+=p;
	}
	cout<<sum;
	return 0;
} 
