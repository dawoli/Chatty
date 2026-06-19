#include<bits/stdc++.h>
using namespace std;
int t,a[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		if(n%7==0)
		{
			for(int i=1;i<=n/7;i++)cout<<8;
		}
		else
		{
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
}
