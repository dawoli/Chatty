#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,a[4][14]={},ans=52;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char c[2];
		int x,y;
		scanf("%s",c);
		if (c[0]=='D') x=0;
		if (c[0]=='C') x=1;
		if (c[0]=='H') x=2;
		if (c[0]=='S') x=3;
		if (c[1]>='2'&&c[1]<='9') y=c[1]-'0';
		if (c[1]=='T') y=10;
		if (c[1]=='J') y=11;
		if (c[1]=='Q') y=12;
		if (c[1]=='K') y=13;
		if (c[1]=='A') y=1;
		a[x][y]=1;
	}
	for (int i=0;i<4;i++)
	{
		for (int j=1;j<=13;j++)
		{
			if (a[i][j]) ans--;
		}
	}
	printf("%d",ans);
}
