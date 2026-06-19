#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char card[14]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	bool c[13]={0},d[13]={0},h[13]={0},s[13]={0};
	while(n--)
	{
		char q,w;
		cin>>q>>w;
		if (q=='D')
		{
			for (int y=0;y<14;y++)
			{
				if (w==card[y])
				{
					d[y]=1;
				}
			 } 
		}
		if (q=='C')
		{
			for (int y=0;y<14;y++)
			{
				if (w==card[y])
				{
					c[y]=1;
				}
			 } 
		}
		if (q=='H')
		{
			for (int y=0;y<14;y++)
			{
				if (w==card[y])
				{
					h[y]=1;
				}
			 } 
		}
		if (q=='S')
		{
			for (int y=0;y<14;y++)
			{
				if (w==card[y])
				{
					s[y]=1;
				}
			 } 
		}
	}
	int sum=0;
	for (int u=0;u<=12;u++)
	{
		if(d[u]==0) sum++;
		if(c[u]==0) sum++;
		if(h[u]==0) sum++;
		if(s[u]==0) sum++;
	}
	cout<<sum;
	return 0;
}
