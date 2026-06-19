#include<bits/stdc++.h>
using namespace std;
int a[15][10];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int num=0;
		string s;
		cin>>s;
		if(s[0]=='D')
		{
			num=1;
		}
		else if(s[0]=='C') 
		{
			num=2;
		}
		else if(s[0]=='H')
		{
			num=3;
		}
		else
		{
			num=4;
		}
		int num2=0;
		if(s[1]=='A')
		{
			num2=1;
		}
		else if(s[1]=='T')
		{
			num2=10;
		}
		else if(s[1]=='J')
		{
			num2=11;
		}
		else if(s[1]=='Q')
		{
			num2=12;
		}
		else if(s[1]=='K')
		{
			num2=13;
		}
		else
		{
			num2=s[1]-'0';
		}
		a[num2][num]=1;
	}
	int num=0;
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(a[i][j]==1)
			{
				num++;
			}
		}
	}
	cout<<52-num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
