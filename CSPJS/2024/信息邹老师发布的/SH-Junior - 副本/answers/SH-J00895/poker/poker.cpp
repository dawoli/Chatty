#include<bits/stdc++.h>
using namespace std;
bool p[5][14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int a,b;
		if(s[0]=='D') a=1;
		else if(s[0]=='C') a=2;
		else if(s[0]=='H') a=3;
		else if(s[0]=='S') a=4;
		if(s[1]>='2'&&s[1]<='9') b=s[1]-'0';
		else if(s[1]=='A') b=1;
		else if(s[1]=='T') b=10;
		else if(s[1]=='J') b=11;
		else if(s[1]=='Q') b=12;
		else if(s[1]=='K') b=13;
		p[a][b]=true;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(p[i][j]==0) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}