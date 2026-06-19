#include <bits/stdc++.h>
using namespace std;
int n,a[5][14],ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string s;
		int x,y;
		int c;
		cin >> s;
		if(s[0]=='D') x=1;
		else if(s[0]=='C') x=2;
		else if(s[0]=='H') x=3;
		else x=4;
		if(s[1]=='T') c=10;
		else if(s[1]=='J') c=11;
		else if(s[1]=='Q') c=12;
		else if(s[1]=='K') c=13;
		else if(s[1]=='A') c=1;
		else c=s[1]-'0';
		if(a[x][c]==0)
		{
			ans++;
			a[x][c]=1;
		}
	}
	cout << 52-ans << endl;
} 
