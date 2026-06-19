#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a,b,c;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cin>>a;
		}
		if(i==2)
		{
			cin>>b; 
		}
		if(i==3)
		{
			cin>>c;
		}
	}
	if(a+b+c>a*2&&a+b+c>b*2&&a+b+c>c*2)
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}

