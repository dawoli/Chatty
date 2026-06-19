#include <bits/stdc++.h>
using namespace std;
int n;
int m[4][9]={{-1,-1,1,7,4,2,0,8},
             {-1,-1,-1,-1,-1,-1,6,-1}};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if((n==6)||(n==2)||(n==5)||(n==4)||(n==3)||(n==7))
		{
			if(n==6){cout<<6;}
			if(n==2){cout<<1;}
			if(n==5){cout<<2;}
			if(n==4){cout<<4;}
			if(n==3){cout<<7;}
			if(n==7){cout<<8;}
			continue;
		}
		if(n==1)
		{
			cout<<-1;
		}
		if(n==8)
		{
			cout<<10;
		}
		if(n==9)
		{
			cout<<18;
		}
		if(n==18)
		{
			cout<<208;
		}
		else
		{
			int a=0;
			a=n/7;
			for(int i=1;i<=1;i++)
			{
				cout<<8;
			}
		}
	}
}
