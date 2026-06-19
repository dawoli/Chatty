#include <iostream>
#include <cstdio>
using namespace std;
bool flag[15][25];
int n; 
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int op;
		int num;
		if('2'<=s[1]&&s[1]<='9') num=s[1]-'0';
		else 
		{
			if(s[1]=='T') num=10;
			else if(s[1]=='J') num=11;
			else if(s[1]=='Q') num=12;
			else if(s[1]=='K') num=13;
			else if(s[1]=='A') num=1;
		}
		if(s[0]=='D') op=1;
		if(s[0]=='C') op=2;
		if(s[0]=='H') op=3;
		if(s[0]=='S') op=4;
		flag[op][num]=true;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(flag[i][j]==false) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
