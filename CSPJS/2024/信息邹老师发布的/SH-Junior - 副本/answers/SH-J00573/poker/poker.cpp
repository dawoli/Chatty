#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,t[5][15],ans;
char poker[2];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>poker[0]>>poker[1];
		int t1,t2;
		if(poker[0]=='D') t1=4;
		else if(poker[0]=='C') t1=3;
		else if(poker[0]=='H') t1=2;
		else if(poker[0]=='S') t1=1;
		if(poker[1]=='A') t2=1;
		else if(poker[1]=='T') t2=10;
		else if(poker[1]=='J') t2=11;
		else if(poker[1]=='Q') t2=12;
		else if(poker[1]=='K') t2=13;
		else t2=poker[1]-'0';
		t[t1][t2]++;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!t[i][j]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
