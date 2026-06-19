#include <bits/stdc++.h>
using namespace std;
int n,ans,a[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		char x,y;
		cin >> x >> y;
		if (x=='D') x=0;
		if (x=='C') x=1;
		if (x=='H') x=2;
		if (x=='S') x=3;
		if (y=='A') y=1;
		if (y=='T') y=10;
		if (y=='J') y=11;
		if (y=='Q') y=12;
		if (y=='K') y=13;
		if ('0'<=y&&y<='9') y-='0';
		a[x*13+y]=1;
	}
	ans=52;
	for (int j=1;j<=52;j++)
	{
		if (a[j]==1)
		{
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}
