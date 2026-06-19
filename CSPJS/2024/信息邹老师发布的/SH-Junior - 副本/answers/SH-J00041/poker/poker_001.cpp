#include<bits/stdc++.h>
using namespace std;
int n;	string s;
int a[5][100];
int m=0;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='D') a[1][s[1]]++;
		if(s[0]=='C') a[2][s[1]]++;
		if(s[0]=='H') a[3][s[1]]++;
		if(s[0]=='S') a[4][s[1]]++;
	}
	int ans=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(a[i][j]!=0) ans++;
		}
	}
	cout<<52-ans<<endl;
	return 0;
}
