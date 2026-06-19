#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool a[10][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(a,false,sizeof(a));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char p[3];
		cin>>p;
		int x,y;
		if(p[0]=='D') x=1;
		if(p[0]=='C') x=2;
		if(p[0]=='H') x=3;
		if(p[0]=='S') x=4;
		if(p[1]>='2'&&p[1]<='9') y=p[1]-'0';
		if(p[1]=='A') y=1;
		if(p[1]=='T') y=10;
		if(p[1]=='J') y=11;
		if(p[1]=='Q') y=12;
		if(p[1]=='K') y=13;
		a[x][y]=true;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==false) ans++;
		}
	}
	cout<<ans;
	return 0;
}
//O(n)
