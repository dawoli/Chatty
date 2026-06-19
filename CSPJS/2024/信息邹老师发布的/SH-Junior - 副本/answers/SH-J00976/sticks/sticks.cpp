#include<bits/stdc++.h>
using namespace std;
int T,n;
void case_1()
{
	for(int i=0;i<n/7;i++)
	{
		cout<<8;
	}
	cout<<endl;
	return;
}
void case_2()
{
	cout<<10;
	for(int i=0;i<n/7-1;i++)
	{
		cout<<8;
	}
	cout<<endl;
	return;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>n;
		if(n%7==0)   case_1();
		if(n%7==1)   case_2();
	}
	return 0;
}
