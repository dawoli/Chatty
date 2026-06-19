#include <bits/stdc++.h>
using namespace std;
int n;
int t;
int main ( ){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++)
	{
		cin>>n;
		if(n<7)
		{
			if(n<2)
				cout<<"-1";
			else if(n==2)
				cout<<"1";
			else if(n==3)
				cout<<"7";
			else if(n==4)
				cout<<"4";
			else if(n==5)
				cout<<"2";
			else if(n==6)
				cout<<"6";
			n=0;
		}
		else if(n%7==1)
		{
			cout<<"10";
			n-=8;
		}
		else if(n%7==2)
		{
			cout<<"18";
			n-=9;
		}
		else if(n%7==3)
		{
			cout<<"23";
			n-=10;
		}
		else if(n%7==4)
		{
			cout<<"20";
			n-=11;
		}
		else if(n%7==5)
		{
			cout<<"28";
			n-=12;
		}
		else if(n%7==6)
		{
			cout<<"68";
			n-=12;
		}
		for(int i=0;i<n/7;i++)
			printf("8");
		cout<<endl;
	}
	return 0; 
}
