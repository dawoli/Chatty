#include<bits/stdc++.h>
using namespace std;
int a[4][14];
void pu(int x,char b)
{
	int f=b-'0';
	if(b=='A') a[x][1]=1;
	else if(b=='T') a[x][10]=1; 
	else if(b=='J') a[x][11]=1;
	else if(b=='Q') a[x][12]=1;
	else if(b=='K') a[x][13]=1;	
	else a[x][f]=1;
	return ;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a;
		cin>>a;
		if(a[0]=='D') pu(0,a[1]);
		if(a[0]=='C') pu(1,a[1]);
		if(a[0]=='H') pu(2,a[1]);
		if(a[0]=='S') pu(3,a[1]);
	}
	int ans=0;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(a[i][j]==0) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
