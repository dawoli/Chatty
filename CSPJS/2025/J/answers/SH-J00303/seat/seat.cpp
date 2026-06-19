#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int m,n,c,b;
	cin>>m>>n;
	int a[m*n];
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	c=a[m+1]%m+1;
	b=a[n]%n+1;
	cout<<c<<b;
	return 0; 
}
