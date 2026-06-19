#include<iostream>
#include<algorithm>
using namespace std;
int count(int a[],int j,int sum)
{
	for(int i=0;i<j;i++)
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
