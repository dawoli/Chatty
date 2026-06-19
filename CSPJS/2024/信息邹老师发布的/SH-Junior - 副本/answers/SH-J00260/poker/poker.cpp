#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
char type[55],num[55];
bool pai[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>type[i]>>num[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(type[i]=='D')
		{
			if(num[i]=='A')
			{
				pai[1][1]=true;
			}
			else if(num[i]=='T')
			{
				pai[1][10]=true;
			}
			else if(num[i]=='J')
			{
				pai[1][11]=true;
			}
			else if(num[i]=='Q')
			{
				pai[1][12]=true;
			}
			else if(num[i]=='K')
			{
				pai[1][13]=true;
			}
			else
			{
				pai[1][num[i]-48]=true;//a==49
			}
		}
		else if(type[i]=='C')
		{
			if(num[i]=='A')
			{
				pai[2][1]=true;
			}
			else if(num[i]=='T')
			{
				pai[2][10]=true;
			}
			else if(num[i]=='J')
			{
				pai[2][11]=true;
			}
			else if(num[i]=='Q')
			{
				pai[2][12]=true;
			}
			else if(num[i]=='K')
			{
				pai[2][13]=true;
			}
			else
			{
				pai[2][num[i]-48]=true;//a==49
			}
		}
		else if(type[i]=='H')
		{
			if(num[i]=='A')
			{
				pai[3][1]=true;
			}
			else if(num[i]=='T')
			{
				pai[3][10]=true;
			}
			else if(num[i]=='J')
			{
				pai[3][11]=true;
			}
			else if(num[i]=='Q')
			{
				pai[3][12]=true;
			}
			else if(num[i]=='K')
			{
				pai[3][13]=true;
			}
			else
			{
				pai[3][num[i]-48]=true;//a==49
			}
		}
		else if(type[i]=='S')
		{
			if(num[i]=='A')
			{
				pai[4][1]=true;
			}
			else if(num[i]=='T')
			{
				pai[4][10]=true;
			}
			else if(num[i]=='J')
			{
				pai[4][11]=true;
			}
			else if(num[i]=='Q')
			{
				pai[4][12]=true;
			}
			else if(num[i]=='K')
			{
				pai[4][13]=true;
			}
			else
			{
				pai[4][num[i]-48]=true;//a==49
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(pai[i][j]) --ans;
		}
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
}
