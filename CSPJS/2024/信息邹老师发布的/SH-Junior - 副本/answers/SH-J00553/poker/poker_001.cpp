#include<bits/stdc++.h>
using namespace std;
int n,b,p[4][14]={0},ans=52;
string a;
int main()
{
    freopen ("poker.in","r",stdin);
	freopen ("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a[1]=='A') b=1;
		if(a[1]=='T') b=10;
		if(a[1]=='J') b=11;
		if(a[1]=='Q') b=12;
		if(a[1]=='K') b=13;
		if(a[1]=='2') b=2;
		if(a[1]=='3') b=3;
		if(a[1]=='4') b=4;
		if(a[1]=='5') b=5;
		if(a[1]=='6') b=6;
		if(a[1]=='7') b=7;
		if(a[1]=='8') b=8;
		if(a[1]=='9') b=9;
		if(a[0]=='D') p[0][b]=1;
		if(a[0]=='C') p[1][b]=1;
		if(a[0]=='H') p[2][b]=1;
		if(a[0]=='S') p[3][b]=1; 
		//printf("%c\n",&c);
	}
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			ans=ans-p[i][j];
		}
	}
	
	printf("%d",ans);
	return 0;
}
