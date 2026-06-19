#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char h[60][60]={};
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int a,f;
		if(s[1]=='A') a=1;
		else if(s[1]=='T') a=10;
		else if(s[1]=='J') a=11;
		else if(s[1]=='Q') a=12;
		else if(s[1]=='K') a=13;
		else a=s[1]-'0';
		if(s[0]=='D') f=1;
		else if(s[0]=='C') f=2;
		else if(s[0]=='H') f=3;
		else if(s[0]=='S') f=4;
		h[f][a]++;
	} 
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(h[i][j]==0) cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
