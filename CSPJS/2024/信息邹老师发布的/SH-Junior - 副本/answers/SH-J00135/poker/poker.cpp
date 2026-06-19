#include <bits/stdc++.h>
using namespace std;
int n;
int flag[10][20];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		int x,y;
		if(a=='D') x=1;
		else if(a=='C') x=2;
		else if(a=='H') x=3;
		else x=4;
		if(b>='2' && b<='9') y=b-'0';
		else if(b=='T') y=10;
		else if(b=='J') y=11;
		else if(b=='Q') y=12;
		else if(b=='A') y=1;
		else y=13;
		flag[x][y]=1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(flag[i][j]==0) cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
 } 
