#include<bits/stdc++.h>
using namespace std;
int n,t1,t2,poker[100][100],ans;
char c[2];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		char c1=c[0],c2=c[1];
		if(c1=='D')t1=1;
		if(c1=='C')t1=2;
		if(c1=='H')t1=3;
		if(c1=='S')t1=4;
		if(c2-'0'>=2&&c2-'0'<=9)t2=c2-'0';
		if(c2=='A')t2=1;
		if(c2=='T')t2=10;
		if(c2=='J')t2=11;
		if(c2=='Q')t2=12;
		if(c2=='K')t2=13;
		poker[t1][t2]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			ans+=!poker[i][j];
	cout<<ans;
	return 0;
}
