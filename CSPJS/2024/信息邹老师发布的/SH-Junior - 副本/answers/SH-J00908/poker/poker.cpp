#include<bits/stdc++.h>
using namespace std;
int n,d[20],c[20],h[20],s[20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while (n--)
	{
		string card;
		cin>>card;
		if (card[0]=='D')
		{
			if (card[1]>='2'&&card[1]<='9')
			{
				d[card[1]-'0']=1;
			}
			if (card[1]=='A')
			{
				d[1]=1;
			}
			if (card[1]=='T')
			{
				d[10]=1;
			}
			if (card[1]=='J')
			{
				d[11]=1;
			}
			if (card[1]=='Q')
			{
				d[12]=1;
			}
			if (card[1]=='K')
			{
				d[13]=1;
			}
		}
		if (card[0]=='C')
		{
			if (card[1]>='2'&&card[1]<='9')
			{
				c[card[1]-'0']=1;
			}
			if (card[1]=='A')
			{
				c[1]=1;
			}
			if (card[1]=='T')
			{
				c[10]=1;
			}
			if (card[1]=='J')
			{
				c[11]=1;
			}
			if (card[1]=='Q')
			{
				c[12]=1;
			}
			if (card[1]=='K')
			{
				c[13]=1;
			}
		}
		if (card[0]=='H')
		{
			if (card[1]>='2'&&card[1]<='9')
			{
				h[card[1]-'0']=1;
			}
			if (card[1]=='A')
			{
				h[1]=1;
			}
			if (card[1]=='T')
			{
				h[10]=1;
			}
			if (card[1]=='J')
			{
				h[11]=1;
			}
			if (card[1]=='Q')
			{
				h[12]=1;
			}
			if (card[1]=='K')
			{
				h[13]=1;
			}
		}
		if (card[0]=='S')
		{
			if (card[1]>='2'&&card[1]<='9')
			{
				s[card[1]-'0']=1;
			}
			if (card[1]=='A')
			{
				s[1]=1;
			}
			if (card[1]=='T')
			{
				s[10]=1;
			}
			if (card[1]=='J')
			{
				s[11]=1;
			}
			if (card[1]=='Q')
			{
				s[12]=1;
			}
			if (card[1]=='K')
			{
				s[13]=1;
			}
		}
	}
	int ans=52;
	for (int i=1;i<=13;i++)
	{
		ans-=s[i]+h[i]+c[i]+d[i];
	}
	cout<<ans;
	return 0;
}
