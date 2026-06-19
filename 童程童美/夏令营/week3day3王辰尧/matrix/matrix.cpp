#include<iostream>
using namespace std;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)cout<<j<<' ';
		for(int k=1;k<=n-i;k++)cout<<i<<' ';
		cout<<endl;	
	}	
	return 0;
} 
