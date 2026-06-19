#include<bits/stdc++.h>
using namespace std;
bool vis[5][14];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	if(n==1)
	{
		char x,y;
		cin>>x>>y;
		cout<<51;
		return 0;
	}
	ans=52-n;
	while(n--)
	{
		char x,y;
		int a,b;
		cin>>x>>y;
		if(x=='D') a=1;
		else if(x=='C') a=2;
		else if(x=='H') a=3;
		else a=4;
		if(y=='1') b=1;
		else if(y=='2') b=2;
		else if(y=='3') b=3;
		else if(y=='4') b=4;
		else if(y=='5') b=5;
		else if(y=='6') b=6;
		else if(y=='7') b=7;
		else if(y=='8') b=8;
		else if(y=='9') b=9;
		else if(y=='T') b=10;
		else if(y=='J') b=11;
		else if(y=='Q') b=12;
		else if(y=='K') b=13;
		if(vis[a][b]) ans++;
		else vis[a][b]=true;
	}
	cout<<ans;
	return 0;
}
