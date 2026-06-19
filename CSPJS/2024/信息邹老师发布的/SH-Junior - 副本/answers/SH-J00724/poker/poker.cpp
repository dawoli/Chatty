#include<bits/stdc++.h>
using namespace std;
int n,b,c,sum=0;
int a[5][14]={0};
char pok[2];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pok;
		if(pok[0]=='D')
		{
			b=1;
		}
		if(pok[0]=='C')
		{
			b=2;
		}
		if(pok[0]=='H')
		{
			b=3;
		}
		if(pok[0]=='S')
		{
			b=4;
		}
		if(pok[1]=='A')
		{
			c=1;
		}
		if(pok[1]=='2')
		{
			c=2;
		}
		if(pok[1]=='3')
		{
			c=3;
		}
		if(pok[1]=='4')
		{
			c=4;
		}
		if(pok[1]=='5')
		{
			c=5;
		}
		if(pok[1]=='6')
		{
			c=6;
		}
		if(pok[1]=='7')
		{
			c=7;
		}
		if(pok[1]=='8')
		{
			c=8;
		}
		if(pok[1]=='9')
		{
			c=9;
		}
		if(pok[1]=='T')
		{
			c=10;
		}
		if(pok[1]=='J')
		{
			c=11;
		}
		if(pok[1]=='Q')
		{
			c=12;
		}
		if(pok[1]=='K')
		{
			c=13;
		}
		a[b][c]++;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==0)
			{
				sum++;
			}
		}
	}
	cout<<sum<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
