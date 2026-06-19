#include<bits/stdc++.h>
using namespace std;
int n,a[55][5],ans=0;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x,y;
		int p,q;
		cin>>x>>y;
		if(x=='D')p=1;
		else if(x=='C')p=2;
		else if(x=='H')p=3;
		else p=4;
		if(y=='A')q=1;
		else if(y=='T')q=10;
		else q=y-'0';
		if(a[q][p]==0)ans++;
		a[q][p]++;
	}
	cout<<52-ans;
	return 0;
}

