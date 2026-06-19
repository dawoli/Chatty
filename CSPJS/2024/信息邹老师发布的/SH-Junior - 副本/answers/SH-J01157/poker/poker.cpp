#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
bool f[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		if(a=='D')
		{
			if(b=='A')      f[1][1]=1;
			else if(b=='T') f[1][10]=1;
			else if(b=='J') f[1][11]=1;
			else if(b=='Q') f[1][12]=1;
			else if(b=='K') f[1][13]=1;
			else            f[1][b-48]=1;
		}
		if(a=='C')
		{
			if(b=='A') f[2][1]=1;
			else if(b=='T') f[2][10]=1;
			else if(b=='J') f[2][11]=1;
			else if(b=='Q') f[2][12]=1;
			else if(b=='K') f[2][13]=1;
			else            f[2][b-48]=1;
		}
		if(a=='H')
		{
			if(b=='A') f[3][1]=1;
			else if(b=='T') f[3][10]=1;
			else if(b=='J') f[3][11]=1;
			else if(b=='Q') f[3][12]=1;
			else if(b=='K') f[3][13]=1;
			else            f[3][b-48]=1;
		}
		if(a=='S')
		{
			if(b=='A') f[4][1]=1;
			else if(b=='T') f[4][10]=1;
			else if(b=='J') f[4][11]=1;
			else if(b=='Q') f[4][12]=1;
			else if(b=='K') f[4][13]=1;
			else            f[4][b-48]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			ans-=f[i][j];
		}
	}
	cout<<ans;
}
