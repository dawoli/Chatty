#include <bits/stdc++.h>
using namespace std;
bool pok[5][15];
int n;
int main()
{
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char s[5];
		cin>>s;
		int x,y;
		if(s[0]=='D')
		{
			x=1;
		}else if(s[0]=='C')
		{
			x=2;
		}else if(s[0]=='H')
		{
			x=3;
		}else if(s[0]=='S')
		{
			x=4;
		}
		if(s[1]=='A')
		{
			y=1;
		}else if((s[1]>='2')&&(s[1]<='9')){
			y=s[1]-'0';
		}else if(s[1]=='T')
			y=10;
		else if(s[1]=='J')y=11;
		else if(s[1]=='Q')y=12;
		else if(s[1]=='K')y=13;
		pok[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!pok[i][j])
			{
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

