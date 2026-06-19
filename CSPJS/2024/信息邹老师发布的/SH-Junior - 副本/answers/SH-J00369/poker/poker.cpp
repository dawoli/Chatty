#include<bits/stdc++.h>
using namespace std;
int n;
int a[4][15];
char color,num;
int c,x,cnt=0;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		getchar();
		cin>>color>>num;
		if (color=='D')
		{
			c=0;
		}
		if (color=='C')
		{
			c=1;
		}
		if (color=='H')
		{
			c=2;
		}
		if (color=='S')
		{
			c=3;
		}
		if (num=='A')
		{
			x=1;
		}
		if (num=='T')
		{
			x=10;
		}
		if (num=='J')
		{
			x=11;
		}
		if (num=='Q')
		{
			x=12;
		}
		if (num=='K')
		{
			x=13;
		}
		if (num>='2'&&num<='9')
		{
			x=num-'0';
		}
		a[c][x]++;
	}
	for (int i=0;i<=3;i++)
	{
		for (int j=1;j<=13;j++)
		{
			if (a[i][j]==0)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;	
 } 
