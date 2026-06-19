#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	bool card_list[5][14];
	int i,j;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=13;j++)
		{
			card_list[i][j]=false;
		}
	}
	char a,b;
	int x,y;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a=='S')
		{
			x=1;
		}
		else if(a=='H')
		{
			x=2;
		}
		else if(a=='D')
		{
			x=3;
		}
		else if(a=='C')
		{
			x=4;
		}
		
		
		
		
		if(b=='A')
		{
			y=1;
		}
		else if(b=='2')
		{
			y=2;
		}
		else if(b=='3')
		{
			y=3;
		}
		else if(b=='4')
		{
			y=4;
		}
		else if(b=='5')
		{
			y=5;
		}
		else if(b=='6')
		{
			y=6;
		}
		else if(b=='7')
		{
			y=7;
		}
		else if(b=='8')
		{
			y=8;
		}
		else if(b=='9')
		{
			y=9;
		}
		else if(b=='T')
		{
			y=10;
		}
		else if(b=='J')
		{
			y=11;
		}
		else if(b=='Q')
		{
			y=12;
		}
		else if(b=='K')
		{
			y=13;
		}
		card_list[x][y]=true;
	}
	int ans=0;
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=13;j++)
		{
			if(card_list[i][j]==false)
			{
				ans+=1;
			}
		}
	}
	cout<<ans;
	return 0;
}
