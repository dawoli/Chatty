#include<bits/stdc++.h>
using namespace std;
int sz[10]={6,2,5,5,4,5,6,3,7,6};
int n;
int s[50000]; 
int w;
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","W",stdout);
	int t;
	cin>>t;
	
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n<=1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
		{
			for(int j=1;j<=n/7;j++)
			{
				cout<<"8";
			}
		}
	}
	return 0;
}
