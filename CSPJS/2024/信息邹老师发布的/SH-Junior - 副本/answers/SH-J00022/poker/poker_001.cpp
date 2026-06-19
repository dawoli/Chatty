#include<bits/stdc++.h>
using namespace std;
int k[4][1000],n,sum=52,x,y;
string a;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a[0]=='D')
		{
			x=0;
		}
		if(a[0]=='C')
		{
			x=1;
		}
		if(a[0]=='S')
		{
			x=2;
		}
		if(a[0]=='H')
		{
			x=3;
		}
		y=a[1]-49;
		
		if(!k[x][y])
		{
			sum--;
			k[x][y]=1;
		}
	}
	cout<<sum;
}
