#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	string s;
	cin>>s;
	int c=1;
	int r=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		c*=a[i];
	}
	if(m==1||m==n)
	{
		r=1;
	}
	else
	{
		r=c;
	}
	cout<<r;
	fclose(stdin);
	return 0;
}
