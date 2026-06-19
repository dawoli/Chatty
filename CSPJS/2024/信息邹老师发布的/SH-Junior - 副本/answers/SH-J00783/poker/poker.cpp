#include<iostream>
#include<cstdio>

using namespace std;

int n,x,y;
int card[5][14];
string c;

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	
	cin>>n;
	while(n--)
	{
		cin>>c;
		if(c[0]=='D') x=1;
		if(c[0]=='C') x=2;
		if(c[0]=='H') x=3;
		if(c[0]=='S') x=4;
		
		if(c[1]=='A') y=1;
		else if(c[1]=='T') y=10;
		else if(c[1]=='J') y=11;
		else if(c[1]=='Q') y=12;
		else if(c[1]=='K') y=13;
		else y=c[1]-'0';
		
		card[x][y]++;
	}
	
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!card[i][j]) ans++;
		 } 
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
