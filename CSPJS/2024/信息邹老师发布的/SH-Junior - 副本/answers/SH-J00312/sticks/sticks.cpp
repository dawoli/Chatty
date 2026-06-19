#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int arr[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,128,108,220,228,208,608,808};

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		cin>>n; 
		if(n<=1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0)
		{
			int k=n/7;
			while(k--) cout<<8;
			cout<<endl;
		}
		
		else if((n-1)%7==0)
		{
			int m=n-8;
			int k=m/7;
			cout<<"10";
			while(k--) cout<<'8';
			cout<<endl;
		}
		
		else
		{
			cout<<arr[n]<<endl; 
		}
	}
	return 0;
}
