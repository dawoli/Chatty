#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int c[15] = {},d[15] = {},e[15] = {},h[15] = {};
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		if(s[0]=='C')
		{
			if(s[1]>='2' && s[1]<='9')
			{
				c[s[1]-'0'] = 1;
			}
			else
			{
				if(s[1]=='A')
					c[1] = 1;
				else if(s[1]=='T')
					c[10] = 1;
				else if(s[1]=='J')
					c[11] = 1;
				else if(s[1]=='Q')
					c[12] = 1;	
				else if(s[1]=='K')
					c[13] = 1;
			}
		}
		if(s[0]=='D')
		{
			if(s[1]>='2' && s[1]<='9')
			{
				d[s[1]-'0'] = 1;
			}
			else
			{
				if(s[1]=='A')
					d[1] = 1;
				else if(s[1]=='T')
					d[10] = 1;
				else if(s[1]=='J')
					d[11] = 1;
				else if(s[1]=='Q')
					d[12] = 1;	
				else if(s[1]=='K')
					d[13] = 1;
			}
		}
		if(s[0]=='S')
		{
			if(s[1]>='2' && s[1]<='9')
			{
				e[s[1]-'0'] = 1;
			}
			else
			{
				if(s[1]=='A')
					e[1] = 1;
				else if(s[1]=='T')
					e[10] = 1;
				else if(s[1]=='J')
					e[11] = 1;
				else if(s[1]=='Q')
					e[12] = 1;	
				else if(s[1]=='K')
					e[13] = 1;
			}
		}
		if(s[0]=='H')
		{
			if(s[1]>='2' && s[1]<='9')
			{
				h[s[1]-'0'] = 1;
			}
			else
			{
				if(s[1]=='A')
					h[1] = 1;
				else if(s[1]=='T')
					h[10] = 1;
				else if(s[1]=='J')
					h[11] = 1;
				else if(s[1]=='Q')
					h[12] = 1;	
				else if(s[1]=='K')
					h[13] = 1;
			}
		}
	}
	int sum = 0;
	for(int i=1;i<=13;i++)
	{
		if(c[i]==0) sum++;
		if(e[i]==0) sum++;
		if(h[i]==0) sum++;
		if(d[i]==0) sum++;
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
