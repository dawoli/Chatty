#include<bits/stdc++.h>
using namespace std;
char a,b;
int n,ans=52,c[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a=='D')
		{
			if(b>='2' && b<='9')
			c[1][(int)(b-'0')]=1;
			if(b=='A')
			c[1][1]=1;
			if(b=='T')
			c[1][10]=1;
			if(b=='J')
			c[1][11]=1;
			if(b=='Q')
			c[1][12]=1;
			if(b=='K')
			c[1][13]=1;
		}
		if(a=='C')
		{
			if(b>='2' && b<='9')
			c[2][(int)(b-'0')]=1;
			if(b=='A')
			c[2][1]=1;
			if(b=='T')
			c[2][10]=1;
			if(b=='J')
			c[2][11]=1;
			if(b=='Q')
			c[2][12]=1;
			if(b=='K')
			c[2][13]=1;
		}
		if(a=='H')
		{
			if(b>='2' && b<='9')
			c[3][(int)(b-'0')]=1;
			if(b=='A')
			c[3][1]=1;
			if(b=='T')
			c[3][10]=1;
			if(b=='J')
			c[3][11]=1;
			if(b=='Q')
			c[3][12]=1;
			if(b=='K')
			c[3][13]=1;
		}
		if(a=='S')
		{
			if(b>='2' && b<='9')
			c[4][(int)(b-'0')]=1;
			if(b=='A')
			c[4][1]=1;
			if(b=='T')
			c[4][10]=1;
			if(b=='J')
			c[4][11]=1;
			if(b=='Q')
			c[4][12]=1;
			if(b=='K')
			c[4][13]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(c[i][j]==1)
			ans--;
		}
	}
	cout<<ans;
	return 0;
} 

