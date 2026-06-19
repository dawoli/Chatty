#include <bits/stdc++.h> 
using namespace std;
bool b[4][13];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char a[2];
	int all=52;
	for(int i=0;i<n;i++)
	{
		cin>>a[0]>>a[1];
		int x,y;
		if(a[0]=='D')
		{
			x=0;
		}
		if(a[0]=='C')
		{
			x=1;
		}
		if(a[0]=='H')
		{
			x=2;
		}
		if(a[0]=='S')
		{
			x=3;
		}
		if(a[1]>='2'&&a[1]<='9')
		{
			y=a[1]-'1';
		}
		else
		{
			if(a[1]=='A')
			{
				y=0;
			}
			if(a[1]=='T')
			{
				y=9;
			}
			if(a[1]=='J')
			{
				y=10;
			}
			if(a[1]=='Q')
			{
				y=11;
			}
			if(a[1]=='K')
			{
				y=12;
			}
		}
		if(b[x][y]==0)
		{
			b[x][y]=1;
			all--;
		}
	}
	cout<<all;
	return 0;
}
