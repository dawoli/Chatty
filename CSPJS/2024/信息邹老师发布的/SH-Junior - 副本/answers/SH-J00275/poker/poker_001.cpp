#include <bits/stdc++.h>
using namespace std;
int judgeCol(char a)
{
	if(a=='D')
		return 4;
	else if(a=='C')
		return 3;
	else if(a=='H')
		return 2;
	else if(a=='S')
		return 1;
}
int judgeNum(char a)
{
	if(a>48&&a<65)
		return a-'0';
	else if(a=='A')
		return 1;
	else if(a=='T')
		return 10;
	else if(a=='J')
		return 11;
	else if(a=='Q')
		return 12;
	else if(a=='K')
		return 13;
}
int rc[14][5];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int m;
	char n,c;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>c>>n;
		int intn=judgeNum(n);
		int intc=judgeCol(c);
		rc[intn][intc]++;
	}
	int ans=0;
	for(int i=1;i<=13;i++)
		for(int j=1;j<=4;j++)
			if(rc[i][j]==0)
				ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
