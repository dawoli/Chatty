#include<bits/stdc++.h>
using namespace std;
bool k[4][14];
int n,ans=0;
string a;
int change(char x)
{
	if(x=='T') return 10;
	if(x=='J') return 11;
	if(x=='Q') return 12;
	if(x=='K') return 13;
	if(x=='A') return 1;
	return x-'0';
}
int ch(char x)
{
	if(x=='D') return 0;
	if(x=='C') return 1;
	if(x=='H') return 2;
	return 3;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		k[ch(a[0])][change(a[1])]=true;
	}
	for(int i=0;i<4;i++)
		for(int j=1;j<=13;j++)
			if(!k[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}
