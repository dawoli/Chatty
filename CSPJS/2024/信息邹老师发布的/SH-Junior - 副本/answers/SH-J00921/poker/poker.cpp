#include<bits/stdc++.h> 
using namespace std;
int n,a,b,ans;
char ch1,ch2;
bool x[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ch1>>ch2;
		if(ch1=='D')
		{
			a=1;
		}
		else if(ch1=='C')
		{
			a=2;
		}
		else if(ch1=='H')
		{
			a=3;
		}
		else if(ch1=='S')
		{
			a=4;
		}
		if(ch2-'0' >=2 and ch2-'0'<=9)
		{
			b=ch2-'0';
		}
		else if(ch2=='A')
		{
			b=1;
		}
		else if(ch2=='T')
		{
			b=10;
		}
		else if(ch2=='J')
		{
			b=11;
		}
		else if(ch2=='Q')
		{
			b=12;
		}
		else
		{
			b=13;
		}
		x[a][b]=1;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(x[i][j] == 1)
			{
				ans++;
			}
		}
	}
	cout<<52-ans;
	return 0;
}
