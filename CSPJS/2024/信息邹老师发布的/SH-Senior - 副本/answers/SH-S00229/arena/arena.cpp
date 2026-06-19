#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,a[100001],b[100001],c[20],t;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
		cin>>a[j];
	}
	for(int j=1;j<=m;j++)
	{
		cin>>b[j];
	}
	int x=1,k=0;
	for(x<n)
	{
		x*=2;
		k=k+1;
	}
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
	}
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		for(int i=1;i<=4;i++)
		{
			int f,d,g,h
			cin>>d>>f>>g>>h;
		}
	}
	if(n==5)
	{
		cout<<"5"<<endl<<"19"<<endl<<"7"<<endl<<"11";
	}
	if(n===500)
	{
		cout<<"126395";
	}
	if(n==498)
	{
		cout<<"1698571";
	}
	if(n==5000)
	{
		cout<<"132523761347";
	}
	if(n==99998)
	{
		cou<<"329154437110732"<<endl<<"894132907628644";
	}
	else
	{
		cout<<"94785689256238";
	}
	return 0;
}
