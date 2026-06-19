#include<bits/stdc++.h>
using namespace std;

int n;
int a[15][5]={0};

void pt(char num,char clr)
{
	int x,y;
	if(num=='A')
	{
		x=1;
	}
	else
	{
		if(num=='T')
		{
			x=10;
		}
		else
		{
			if(num=='J')
			{
				x=11;
			}
			else
			{
				if(num=='Q')
				{
					x=12;
				}
				else
				{
					if(num=='K')
					{
						x=13;
					}
					else
					{
						x=num-'0';
					}
				}
			}
		}
	}
	
	if(clr=='S')
	{
		y=0;
	}
	else
	{
		if(clr=='H')
		{
			y=1;
		}
		else
		{
			if(clr=='C')
			{
				y=2;
			}
			else
			{
				y=3;
			}
		}
	}
	
	a[x][y]=1;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char num;
		char clr;
		cin>>clr>>num;
		pt(num,clr);
	}
	
	int ans=52;
	for(int i=1;i<=13;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j])
			{
				ans--;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
