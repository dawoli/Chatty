#include <iostream>
#include <cstdio>
using namespace std;
bool f[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		int A,B;
		if(a=='D') A=1;
		else if(a=='C') A=2;
		else if(a=='H') A=3;
		else A=4;
		if('2'<=b&&b<='9') B=b-'0';
		else if(b=='A') B=1;
		else if(b=='T') B=10;
		else if(b=='J') B=11;
		else if(b=='Q') B=12;
		else if(b=='K') B=13;
		f[A][B]=true;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(!f[i][j]) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
